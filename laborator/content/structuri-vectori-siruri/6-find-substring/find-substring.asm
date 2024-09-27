%include "../utils/printf32.asm"

section .data
source_text: db "ABCABCBABCBABCBBBABABBCBABCBAAACCCB", 0
substring: db "BABC", 0

print_format: db "Substring found at index: %d", 10, 0

section .text
extern printf
extern strlen
global main
main:
    push ebp
    mov ebp, esp

    push substring
    call strlen
    add esp, 4
    mov ecx, eax
    add ecx, source_text
    dec ecx

    ; TODO: Print the start indices for all occurrences of the substring in source_text

    mov ebx, source_text
    mov edx, substring

loopp:
    cmp byte [ebx], 0
    je exit
    mov al, byte [edx]
    cmp byte [ebx], al
    je increment
    mov edx, substring
    jmp next;
increment:
    inc edx
next:
    cmp byte [edx], 0
    jne end
    mov eax, ebx
    sub eax, ecx
    PRINTF32 `Substring found at index: %d\n\x0`, eax
    mov edx, substring
end:
    inc ebx
    jmp loopp

exit:
    leave
    ret
