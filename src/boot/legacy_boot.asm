; VectorOS
; File name		: boot/legacy_boot.asm 
; Creation date	: 2025/11/10 14:16 (Mon)

Start:

	times 510 - ($ - $$) db 0
	dw 0xaa55
