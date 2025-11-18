/* VectorOS
 * File name		: kernel/process/vector_process.c
 * Creation date	: 2025/11/04 00:59 (Tues)
 */

#include "vector_process.h"
#include "../vector_errno.h"
#include "../memory/vector_malloc.h"

#include <stdbool.h>

#ifndef NULL
#define NULL ((void *)0)
#endif

Pid_Index			_pid_pioneer = 0;
Pid_Recycle_Pool	*_pid_recycle_pool = NULL;
Proc_Vec_Table		_process_vector_table[PROCESS_CAPACITY] = {NULL};

bool _pid_register_lock = false;

/* Do one thing, and do it well. */

int init_process(Process pinit)
{
	process_fork(pinit, 0, 0);
}

int process_fork(Process process, Pid_Index master_pid, User_Index user, enum Process_Level level, enum Process_Priority priority)
{
	Pid_Recycle_Pool *temp_pid_node;

	if ((process = (Process)kernel_malloc(sizeof(_Process))))	return KERNEL_EXIT_FAILURE;

	while (true)
	{
		if (!_pid_register_lock)
		{
			_pid_register_lock = true;

			if (_pid_recycle_pool)
			{
				process -> pid		= _pid_recycle_pool -> pid;
				temp_pid_node		= _pid_recycle_pool;
				_pid_recycle_pool	= _pid_recycle_pool -> next;
				kernel_free(temp_pid_node);
			}
			else
			{
				if (_pid_pioneer == PROCESS_CAPACITY - 1)
				{
					kernel_free(process);
					_pid_register_lock = false;
					return KERNEL_STANDABLE_WARN;
				}
				process -> pid = _pid_pioneer ++;
			}

			_pid_register_lock = false;
			break;
		}
	}

	process -> master_pid	= master_pid;
	process -> user			= user;
	process -> level		= level;
	process -> priority		= priority;
	process -> state		= PROC_ACTIVE;

	_process_vector_table[process -> pid] = process;

	return KERNEL_EXIT_SUCCESS;
}

int process_destroy(Pid_Index pid)
{
	Pid_Recycle_Pool *new_pid_node;

	while (true)
	{	
		if (!_pid_register_lock)
		{
			_pid_register_lock = true;

			if (kernel_free(_process_vector_table[pid]))	return KERNEL_EXIT_FAILURE;
			_process_vector_table[pid] = NULL;

			if (pid == _pid_pioneer - 1)	_pid_pioneer --;
			else
			{
				if ((new_pid_node = (Pid_Recycle_Pool)kernel_malloc(sizeof(_Pid_Recycle_Pool))))
					return KERNEL_EXIT_FAILURE;

				new_pid_node -> pid		= pid;
				new_pid_node -> next	= _pid_recycle_pool;
				_pid_recycle_pool		= new_pid_node;
			}

			_pid_register_lock = false;
		}
	}

	return KERNEL_EXIT_SUCCESS;
}
