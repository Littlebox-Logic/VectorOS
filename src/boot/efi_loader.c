/* VectorOS
 * File name		: boot/efi_loader.c
 * Creation date	: 2025/11/14 10:28 (Tues)
 */

#include "efi_loader.h"

#include <efi.h>
#include <efilib.h>

EFI_STATUS EFIAPI efi_main(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *system_table)
{
	Print(L"Hello world.");
	return EFI_SUCCESS;
}
