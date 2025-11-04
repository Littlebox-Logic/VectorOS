/* VectorOS
 * File name		: boot/efi_loader.h
 * Creation date	: 2025/11/14 10:29 (Tues)
 */

#ifndef EFI_LOADER_H
#define EFI_LOADER_H

/* Basic kernel info. */
typedef struct
{
	UINT64 kernel_entry;		/* ---  0 bytes --- */
	UINT64 kernel_size;
	UINT64 memory_map;
	UINT64 memory_map_size;
	UINT64 descriptor_size;		/* --- 40 bytes--- */
}	_Kernel_Info, *Kernel_Info;

/* ELF header. */
typedef struct
{
	UINT32	magic;				/* ---  0 bytes --- */
	UINT8	arch;
	UINT8	byte_order;
	UINT8	header_version;
	UINT8	abi;				/* ---  8 bytes --- */
	UINT16	type;				/* ---  8 bytes --- */
	UINT16	machine;
	UINT32	version;			/* --- 16 bytes --- */
	UINT64	entry;
	UINT64	phoff;
	UINT64	shoff;
	UINT32	flags;
	UINT16	ehsize;
	UINT16	phentsize;
	UINT16	phnum;
	UINT16	shentsize;
	UINT16	shnum;
	UINT16	shstrndx;			/* --- 56 bytes --- */
}	_EFI_Header, *EFI_Header;

#endif
