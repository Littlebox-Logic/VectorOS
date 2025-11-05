/* VectorOS
 * File name		: kernel/process/vector_process.h 
 * Creation date	: 2025/11/04 00:53 (Tues)
 */

#ifndef VECTOR_PROCESS_H
#define VECTOR_PROCESS_H

#include <stdint.h>

enum Process_Priority
{
	PRIO_REALTIME	= 0;
	PRIO_HIGH		= 1;
	PRIO_NORMAL		= 2;
	PRIO_LOW		= 3;
	PRIO_IDLE		= 4;
}

enum Process_Level
{
	PROC_KERNEL		= 0;
	PROC_SERVICE	= 1;
	PROC_RESERVED	= 2;
	PROC_USER		= 3;
}

enum Process_State
{
	PROC_ACTIVE		= 0;
	PROC_SLEEP		= 1;
	PROC_BLOCKED	= 2;
	PROC_TERMINATED	= 3;
}

typedef uint32_t Pid_Index;
typedef uint16_t User_Index;

typedef struct
{
	Pid_Index				pid;
	Pid_Index				master_pid;
	User_Index				user;
	enum Process_Priority	priority;
	enum Process_Level		level;
	enum Process_State		state;
	const char *path;
}	_Process, *Process;

int process_fork(Process);

#endif
