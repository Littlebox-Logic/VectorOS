# VectorOS
# File name		: Makefile 
# Creation date	: 2025/11/14 00:04 (Tues)

CC = gcc
LD = ld
OBJCOPY = objcopy

EFI_CFLAGS	= -I/usr/include/efi -I/usr/include/efi/x86_64 -DEFI_FUNCTION_WRAPPER -fPIC -fshort-wchar -ffreestanding -fno-stack-protector -mno-red-zone -std=gnu23 -Wall -O2
EFI_LDFLAGS	= -T /usr/lib/elf_x86_64_efi.lds -shared -Bsymbolic -L/usr/lib -lgnuefi -lefi

all:				bin/bootx64.efi

bin/bootx64.efi:	obj/efi_loader.o
	$(LD) $(EFI_LDFLAGS) /usr/lib/crt0-efi-x86_64.o obj/efi_loader.o -o $@

obj/efi_loader.o:	src/boot/efi_loader.c
	$(CC) $(EFI_CFLAGS) -c -o $@ $<

clean:
	rm -rf bin/*
	rm -rf obj/*
