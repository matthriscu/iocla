%include "printf32.asm"

section .text
	global main
	extern printf

main:
	;cele doua multimi se gasesc in eax si ebx
	mov eax, 139 ; 7, 3, 1, 0
	mov ebx, 169 ; 7, 5, 3, 0
	PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
	PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime

	; TODO1: reuniunea a doua multimi

	mov edx, eax
	or edx, ebx
	PRINTF32 `%u\n\x0`, edx ; afiseaza reuniunea

	; TODO2: adaugarea unui element in multime

	mov edx, 1
;	shl edx, 5
	or eax, edx ; adauga 5 in multimea a

	mov edx, 1
;	shl edx, 2
	or ebx, edx ; adauga 2 in multimea b

	PRINTF32 `%u\n\x0`, eax ; afiseaza prima multime
	PRINTF32 `%u\n\x0`, ebx ; afiseaza cea de-a doua multime

	; TODO3: intersectia a doua multimi

	mov edx, eax
	and edx, ebx

	PRINTF32 `%u\n\x0`, edx ; afiseaza intersectia

	; TODO4: complementul unei multimi

	mov edx, eax
	not edx

	PRINTF32 `%u\n\x0`, edx ; afiseaza complementul

	; TODO5: eliminarea unui element

	mov edx, 1
	shl edx, 5
	not edx
	and eax, edx ; elimina 5 din multimea a

	PRINTF32 `%u\n\x0`, eax ; afiseaza a

	; TODO6: diferenta de multimi EAX-EBX

	mov edx, ebx
	not edx
	and edx, eax

	PRINTF32 `%u\n\x0`, eax ; afiseaza a-b

	xor eax, eax
	ret
