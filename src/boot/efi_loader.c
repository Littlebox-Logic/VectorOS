/* VectorOS
 * File name		: boot/efi_loader.c
 * Creation date	: 2025/11/04 10:28 (Tues)
 */

#include "efi_loader.h"

#include <efi.h>
#include <efilib.h>
#include <stdbool.h>

EFI_STATUS EFIAPI efi_main(EFI_HANDLE image_handle, EFI_SYSTEM_TABLE *system_table)
{
	InitializeLib(image_handle, system_table);
	system_table -> ConOut -> ClearScreen(system_table -> ConOut);
	Print(L"Hello world. - Vector OS 0.1.0.0 (Build 0)\n\n");
	Print(L"System Info:\n");
	Print(L"\tFirmware Vendor   : %s\n", system_table -> FirmwareVendor);
	Print(L"\tFirmware Revision : %d\n", system_table -> FirmwareRevision);
	Print(L"\tEFI Specification : %d.%02d\n", system_table -> Hdr.Revision >> 16, system_table -> Hdr.Revision & 0xFFFF);

	Print(L"\nPress any key to continue...");

	/*EFI_INPUT_KEY Key;
	system_table -> ConIn -> Reset(system_table -> ConIn, FALSE);

	while (system_table -> ConIn -> ReadKeyStroke(system_table -> ConIn, &Key) == EFI_NOT_READY)
		system_table->BootServices->Stall(10000);
*/
	WaitForSingleEvent(system_table -> ConIn ->WaitForKey, 0);

	return EFI_SUCCESS;
}
