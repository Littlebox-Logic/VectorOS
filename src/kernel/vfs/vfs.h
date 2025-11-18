/* VectorOS
 * File name		: kernel/vfs/vfs.h
 * Creation date	: 2025/11/10 17:36 (Mon)
 */

#ifndef VFS_H
#define VFS_H

#include <stdint.h>

#define GRP_ROOT 0
#define GRP_READ 1
#define GRP_SERV 2
#define GRP_USER 3

typedef struct
{
	char		path[32];
	uint32_t	owner;
	uint16_t	permission;
	uint8_t		group;
}	_VFile, *VFile;

int vfs_create(const char *, uint32_t, uint8_t);

#endif
