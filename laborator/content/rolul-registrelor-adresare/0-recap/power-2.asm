%include "../utils/printf32.asm"

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov eax, 211    ; to be broken down into powers of 2
    mov ebx, 1      ; stores the current power

    ; TODO - print the powers of 2 that generate number stored in EAX

loop:
    cmp eax, ebx
    jl exit
    mov edx, ebx
    and edx, eax
    shl ebx, 1
    cmp edx, 0
    jz loop
    PRINTF32 `%u\n\x0`, edx
    jmp loop

exit:    
    leave
    ret
