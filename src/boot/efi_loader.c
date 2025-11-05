/* VectorOS
 * File name		: boot/efi_loader.c
 * Creation date	: 2025/11/04 10:28 (Tues)
 */

#include "efi_loader.h"

#include <efi.h>
#include <efilib.h>

EFI_STATUS EFIAPI efi_main(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *system_table)
{
	Print(L"Hello world.");
	while (1);
	return EFI_SUCCESS;
}
