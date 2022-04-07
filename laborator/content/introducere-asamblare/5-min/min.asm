%include "printf32.asm"

section .text
    global main
    extern printf

main:
    ;cele doua numere se gasesc in eax si ebx
    mov eax, 4
    mov ebx, 1

    cmp eax, ebx
    ; TODO: aflati minimul
    jl print
    mov eax, ebx

print:
    PRINTF32 `%d\n\x0`, eax ; afiseaza minimul
    ret
