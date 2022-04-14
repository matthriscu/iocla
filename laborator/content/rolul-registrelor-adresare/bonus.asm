%include "../utils/printf32.asm"

%define ARRAY_SIZE    10

section .data
    pos_array dd 1392849, 12544, 879923, 8799279, 7202277, 971872, 28789292, 17897892, 12987, 8799201
    array dd 1392849, -12544, 879923, -8799279, -7202277, 971872, 28789292, -17897892, -12987, -8799201

section .text
extern printf
global main
main:
    push ebp
    mov ebp, esp

    mov ecx, ARRAY_SIZE
    xor eax, eax

count_odd_elements:
    mov edx, dword [pos_array + 4*(ecx - 1)]
    and edx, 1
    add eax, edx
    loop count_odd_elements
    
    PRINTF32 `%u \x0`, eax

    mov ecx, ARRAY_SIZE
    xor eax, eax
count_neg_elements:
    mov edx, dword [array + 4*(ecx - 1)]
    cmp edx, 0
    jge skip
    inc eax
skip:
    loop count_neg_elements

    PRINTF32 `%u\n\x0`, eax

    leave
    ret
