/* VectorOS
 * File name		: kernel/kernel_scheduler.h
 * Creation date	: 2025/11/10 14:23 (Mon)
 */

#ifndef KERNEL_SCHEDULER_H
#define KERNEL_SCHEDULER_H

#include <stdint.h>

#define KERNEL_MAX_NUM 16

typedef uint64_t Index;

typedef struct
{
	Index kernel_index;
	Index processor_index;
}	_Kernel, *Kernel;

int kernel_fork(Kernel);

#endif
