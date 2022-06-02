section .data
    before_format db "before %s", 13, 10, 0
    after_format db "after %s", 13, 10, 0
    mystring db "abcdefghij", 0

section .text

extern printf
global main

toupper:
    push ebp
    mov ebp, esp

    ; TODO
    mov ebx, mystring

solve:
    cmp byte [ebx], 'a'
    jl end
    cmp byte [ebx], 'z'
    jg end
    and byte [ebx], 223

end:
    inc ebx
    cmp byte [ebx], 0
    jz out
    jmp solve

out:
    leave
    ret

main:
    push ebp
    mov ebp, esp

    push mystring
    push before_format
    call printf
    add esp, 8

    push mystring
    call toupper
    add esp, 4

    push mystring
    push after_format
    call printf
    add esp, 8

    leave
    ret
