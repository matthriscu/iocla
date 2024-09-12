%include "printf32.asm"

section .text
    global main
    extern printf

main:
    mov ecx, 7       ; vrem sa aflam al N-lea numar; N = 7
    mov eax, 0
    mov ebx, 1

    ; TODO: calculati al N-lea numar fibonacci (f(0) = 0, f(1) = 1)

calc_fib:
    mov edx, ebx
    add edx, eax
    mov eax, ebx
    mov ebx, edx
    loop calc_fib

    PRINTF32 `%d\n\x0`, eax ; afiseaza minimul
    
    ret
