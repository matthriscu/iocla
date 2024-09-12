%include "printf32.asm"

section .data
	helloString: db "Hello, World!", 0
	goodbyeString: db "Goodbye, World!", 0

section .text
	global main
	extern printf

main:
	mov ecx, 6
	mov eax, 1
	mov ebx, 1
	cmp eax, ebx
	jl exit

print:
	cmp ecx, 0
	je exit
	sub ecx, 1
	PRINTF32 `%s\n\x0`, helloString
	jmp print

exit:
	PRINTF32 `%s\n\x0`, goodbyeString
	ret
