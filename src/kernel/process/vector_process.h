/* VectorOS
 * File name		: kernel/process/vector_process.h 
 * Creation date	: 2025/11/04 00:53 (Tues)
 */

#ifndef VECTOR_PROCESS_H
#define VECTOR_PROCESS_H

#include <stdint.h>

typedef uint32_t Pid_Index;
typedef uint16_t User_Index;
typedef uint8_t  Process_Level;

typedef struct
{
	Pid_Index		pid;
	Pid_Index		master_pid;
	User_Index		user;
	Process_Level	level;
	const char *path;
}	_Process, *Process;

int process_fork(Process);

#endif
