/* VectorOS
 * File name		: kernel/process/vector_process.c
 * Creation date	: 2025/11/04 00:59 (Tues)
 */

#include "vector_process.h"
#include "../vector_errno.h"
#include "../memory/vector_malloc.h"

Pid_Index pid = 0;

/* Do one thing, and do it well. */

int init_process(Process pinit)
{
	process_fork(pinit, 0, 0);
}

int process_fork(Process process, Pid_Index master_pid, User_Index user, Process_Level level)
{
	if ((process = (Process)kernel_malloc(sizeof(_process))))
	{
		return KERNEL_EXIT_FAILURE;
	}

	process->pid		= get_new_pid();
	process->master_pid	= master_pid;
	process->user		= user;
	process->level		= level;

	return KERNEL_EXIT_SUCCESS;
}
