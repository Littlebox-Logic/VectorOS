/* VectorOS
 * File name		: kernel/kernel_scheduler.c 
 * Creation date	: 2025/11/10 14:23 (Mon)
 */

#include "kernel_scheduler.h"
#include "vector_errno.h"
#include "vfs/vfs.h"
#include "../cstdlib/string.h"
#include "internal_version.h"

#include <stdbool.h>

Index kernel_count = 0;
Kernel kernel_table[KERNEL_MAX_NUM] = {NULL};

int kernel_scheduler_init(void)
{
	vfs_create("/sysinfo/kernel-count", 0, GRP_);
}

int kernel_fork(Kernel kernel)
{
	char kernel_file[32] = {'\0'};

	if (kernel_count == KERNEL_MAX_NUM)	return KERNEL_STANDABLE_WARN;

	sprintf(kernel_file, "/kernel/vector%uk%u", internal_version, kernel_count ++);
	vfs_create(kernel_file);

	return KERNEL_EXIT_SUCCESS;
}

void kernel_scheduler(void)
{
	kernel_scheduler_init();
	kernel_fork(kernel_table[0]);
	while (true);
}
