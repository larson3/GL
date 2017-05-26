;nothing yet

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define STRLEN 32
			SECTION .bss
tempVal: resb 64					; value of char
position: resb 32
len:	resb 32
			SECTION .text
    global prt_dec



prt_dec:
	push 	eax
	push 	ebx
	push 	ecx
	push 	edx
	xor		eax,eax
	xor		ebx,ebx
	xor		ecx,ecx
	

	xor		edx,edx
	mov		eax,[esp+20]			;getting our value
	mov		ebx,10					;divisor
	mov		ecx,0
	mov		[len],ecx				;making sure evreything is 0
L1_sizeLoop:					;this loop simply finds the size of the int
	xor		edx,edx
	div		ebx
	inc		ecx
	cmp		eax,0
	jne		L1_sizeLoop
	
	;mov		[len],ecx			;storing the size
	
	mov		eax,ecx
	mov		ebx,4
	mul		ebx
	mov		ecx,eax
	mov		[len],ecx
	mov		eax,[esp+20]
L1_divLoop:
	xor		edx,edx
	mov		ebx,10					;divisor



	
	div		ebx					;dividing into eax and eadx
	add		edx,"0"				;making a printable int

	mov		[tempVal+ecx-1],edx	;putting the result into a string

	sub 	ecx,4
	cmp		ecx,0
	jne		L1_divLoop
	
	mov     eax, SYSCALL_WRITE      ; write message
    mov     ebx, STDOUT
    mov     ecx, tempVal
    mov     edx, [len]	; LF is a single character
    int     080h
	
	pop		edx
	pop		ecx
	pop		ebx
	pop		eax
	ret

	

