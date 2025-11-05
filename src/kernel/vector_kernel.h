/* VectorOS
 * File name		: kernel/vector_kernel.h
 * Creation date	: 2025/11/04 00:18 (Tues)
 */

#ifndef VECTOR_KERNEL_H
#define VECTOR_KERNEL_H

#include <stdint.h>

typedef struct
{
	uint64_t total_ram;
}	_kernel_boot_info, *Kernel_Boot_Info;

#endif
