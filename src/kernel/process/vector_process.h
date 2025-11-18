/* VectorOS
 * File name		: kernel/process/vector_process.h 
 * Creation date	: 2025/11/04 00:53 (Tues)
 */

#ifndef VECTOR_PROCESS_H
#define VECTOR_PROCESS_H

#include <stdint.h>

#define PROCESS_CAPACITY 65536

enum Process_Priority
{
	PRIO_REALTIME	= 0,
	PRIO_HIGH		= 1,
	PRIO_NORMAL		= 2,
	PRIO_LOW		= 3,
	PRIO_IDLE		= 4
};

enum Process_Level
{
	PROC_KERNEL		= 0,
	PROC_SERVICE	= 1,
	PROC_RESERVED	= 2,
	PROC_USER		= 3
};

enum Process_State
{
	PROC_ACTIVE		= 0,
	PROC_SLEEP		= 1,
	PROC_BLOCKED	= 2,
	PROC_TERMINATED	= 3
};

typedef uint16_t Pid_Index;
typedef uint16_t User_Index;

typedef struct
{
	Pid_Index				pid;
	Pid_Index				master_pid;
	User_Index				user;
	enum Process_Priority	priority;
	enum Process_Level		level;
	enum Process_State		state;
	const char path[256];
}	_Process, *Process;

typedef struct _Pid_Recycle_Pool_Struct
{
	Pid_Index pid;
	struct _Pid_Recycle_Pool_Struct *next;
}	_Pid_Recycle_Pool, *Pid_Recycle_Pool;

typedef Process Proc_Vec_Table;

extern Pid_Index		_proc_pioneer;
extern Pid_Index		*_pid_recycle_pool; 
extern Proc_Vec_Table	_process_vector_table[PROCESS_CAPACITY];

int process_fork(Process, Pid_Index, User_Index, enum Process_Level, enum Process_Priority);
int process_destroy(Pid_Index);

#endif
