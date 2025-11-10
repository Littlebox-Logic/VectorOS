/* VectorOS
 * File name		: kernel/vfs/vfs.c 
 * Creation date	: 2025/11/10 17:36 (Mon)
 */

#include "vfs.h"

VFile virtual_file_table = NULL;

int vfs_create(const char *path)
{
	return KERNEL_EXIT_SUCCESS;
}
