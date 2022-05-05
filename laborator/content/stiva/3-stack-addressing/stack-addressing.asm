%include "../utils/printf32.asm"

%define NUM 5
   
section .text

extern printf
global main
main:
    mov ebp, esp

    ; TODO 1: replace every push by an equivalent sequence of commands (use direct addressing of memory. Hint: esp)
    mov ecx, NUM
push_nums:
    ;push ecx
    sub esp, 4
    mov dword [esp], ecx
    loop push_nums

    ;push 0
    ;push "mere"
    ;push "are "
    ;push "Ana "

    sub esp, 16
    mov dword [esp], "Ana "
    mov dword [esp + 4], "are "
    mov dword [esp + 8], "mere"
    mov dword [esp + 12], 0

    lea esi, [esp]
    PRINTF32 `%s\n\x0`, esi

    ; TODO 2: print the stack in "address: value" format in the range of [ESP:EBP]
    ; use PRINTF32 macro - see format above
    mov ecx, ebp
    inc ecx
print_bytes:
    PRINTF32 `%p: \n\x0`, ecx
    PRINTF32 `%hhx\n\x0`, [ecx]
    dec ecx
    cmp ecx, esp
    jge print_bytes

    ; TODO 3: print the string
    mov ecx, 0
    mov eax, esp
print_string:
    PRINTF32 `%c\n\x0`, [eax + ecx]
    inc ecx
    cmp byte [eax + ecx], 0
    jne print_string
    PRINTF32 `\n\x0`


    ; TODO 4: print the array on the stack, element by element.
    mov eax, ebp
    sub eax, 4
    mov ecx, NUM
print_array:
    PRINTF32 `%d \x0`, [eax]
    sub eax, 4
    loop print_array
    PRINTF32 `\n\x0`

    ; restore the previous value of the EBP (Base Pointer)
    mov esp, ebp

    ; exit without errors
    xor eax, eax
    ret
