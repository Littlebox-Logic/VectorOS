/* VectorOS
 * File name		: kernel/vfs/vfs.c 
 * Creation date	: 2025/11/10 17:36 (Mon)
 */

#include "vfs.h"
#include "../cstdlib/string.h"

VFile virtual_file_table = NULL;

int vfs_create(const char *path, uint32_t owner, uint8_t group)
{
	VFile target_vfile;
	if(!(target_vfile = (VFile)kernel_malloc(sizeof(_VFile))))		return KERNEL_EXIT_FAILURE;
	if (target_vfile -> path != strcpy(target_vfile -> path, path))	return KERNEL_EXIT_FAILURE;
	target_vfile -> owner = owner;
	target_vfile -> group = group;

	// ...

	return KERNEL_EXIT_SUCCESS;
}
