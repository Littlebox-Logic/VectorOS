# VectorOS
# File name		: Makefile 
# Creation date	: 2025/11/04 00:04 (Tues)

CC = gcc
LD = ld
AR = ar
OBJCOPY = objcopy

EFI_CFLAGS	= -I/usr/include/efi -I/usr/include/efi/x86_64 -DEFI_FUNCTION_WRAPPER -fPIC -fshort-wchar -ffreestanding -fno-stack-protector -mno-red-zone -fno-stack-check -maccumulate-outgoing-args -std=gnu23 -Wall -O2
EFI_LDFLAGS	= -T /usr/lib/elf_x86_64_efi.lds -shared -Bsymbolic -L/usr/lib -lgnuefi -lefi -nostdlib -znocombreloc -L /usr/lib -l:libgnuefi.a -l:libefi.a

CFLAGS		= -std=gnu23 -Wall -O2
KER_LDFLAGS	= -static -nostdlib

all:				bin/bootx64.efi bin/vector.ker bin/kernel_scheduler.ker

# boot core -----------------------------------------------------------

bin/bootx64.efi:	bin/bootx64.so
	$(OBJCOPY) -j .text -j .sdata -j .data -j .dynamic -j .dynsym -j .rel -j .rela -j .reloc --target=efi-app-x86_64 $< $@

bin/bootx64.so:		obj/boot/efi_loader.o
	$(LD) $(EFI_LDFLAGS) /usr/lib/crt0-efi-x86_64.o $< -o $@

obj/boot/efi_loader.o:	src/boot/efi_loader.c
	$(CC) $(EFI_CFLAGS) -c -o $@ $<

# C standard library --------------------------------------------------

lib/vector_cstdlib.a:	obj/cstdlib/math.o obj/cstdlib/string.o
	$(AR) rcs $@ $<

obj/cstdlib/math.o:		src/cstdlib/math.c src/cstdlib/math.h
	$(CC) $(CFLAGS) -c -o $@ src/cstdlib/math.c

obj/cstdlib/string.o:	src/cstdlib/string.c src/cstdlib/string.h
	$(CC) $(CFLAGS) -c -o $@ src/cstdlib/string.c

# kernel --------------------------------------------------------------

bin/vector.ker:				obj/kernel/vector_kernel.o obj/kernel/fs_fat32.o obj/kernel/vector_malloc.o # obj/kernel/vector_process.o obj/kernel/vector_traceback.o obj/kernel/vector_users.o
	$(LD) $(KER_LDFLAGS) $< -o $@

obj/kernel/vector_kernel.o:	src/kernel/vector_kernel.c src/kernel/vector_kernel.h
	$(CC) $(CFLAGS) -c -o $@ src/kernel/vector_kernel.c

obj/kernel/fs_fat32.o:		src/kernel/filesystem/fs_fat32.c src/kernel/filesystem/fs_fat32.h
	$(CC) $(CFALGS) -c -o $@ src/kernel/filesystem/fs_fat32.c

obj/kernel/vector_malloc.o:		src/kernel/memory/vector_malloc.c src/kernel/memory/vector_malloc.h
	$(CC) $(CFALGS) -c -o $@ src/kernel/memory/vector_malloc.c

# kernel scheduler ----------------------------------------------------

bin/kernel_scheduler.ker:		obj/kernel/kernel_scheduler.o
	$(LD) $(KER_LDFLAGS) $< -o $@

obj/kernel/kernel_scheduler.o:	src/kernel/kernel_scheduler.c src/kernel/kernel_scheduler.c
	$(CC) $(CFLAGS) -c -o $@ src/kernel/kernel_scheduler.c

clean:
	rm -rf bin/*
	rm -rf obj/boot/* obj/kernel/* obj/cstdlib/*
