;File: bookcmp.asm
;Project: CMSC 313 Project 4, Fall 2015
;Author: John Larson
;Date: 10/20/2015
;E-mail: larson3@umbc.edu
;This file contains the entirety of the bookcmp.asm which will take
;two book structs and compare their years, if the years are equal it
;will check the names to decide which is lower.


%define TITLE_OFFSET 0
%define AUTHOR_OFFSET 33
%define SUBJECT_OFFSET 54
%define YEAR_OFFSET 68
;our structs are 72 bytes
extern book1, book2


        SECTION .data                   ; initialized data section
		
		
		SECTION .bss                    ; uninitialized data section
		
		SECTION .text                   ; Code section.
		global bookcmp
		

bookcmp:
	    push    ebp						;pushing everything we may need
        mov     ebp, esp
		push 	ebx				
		push 	ecx
		push 	edx
		push 	edi
		push 	esi
		
		mov		ecx,[book1+YEAR_OFFSET]	;moving the year values into registers
		mov		edx,[book2+YEAR_OFFSET]
		

		cmp 	ecx,edx					;comparing the integers
		jg		L1_greater
		jl		L1_less
		mov 	eax,0					;if they are equal we move to
		mov 	ecx,0					;strCmp
		jmp		L1_strCmp
		
	
	
L1_greater:
		mov		eax,1					;return value of 1, which means
		jmp		L1_finish				;we switch on the outside
L1_less:
		mov 	eax,-1
		jmp		L1_finish
		
		
L1_strCmp:
		
		lea 	esi,[book1+ecx]		;store a pointer to the start of the
		lea		edi,[book2+ecx]		;book2 title char array.
		mov 	bl, byte[esi]		;moving one byte at a time into 8bit
		mov		dl, byte[edi] 		;registers.
		cmp		bl,dl
		jg		L1_greater
		jl		L1_less
		cmp 	bl,0
		je		L1_less
		inc 	ecx					;let's look at the next byte
		jmp 	L1_strCmp
		
L1_finish:
		pop 	esi					;popping everything back
		pop 	edi
		pop 	edx
		pop 	ecx
		pop 	ebx
		pop 	ebp
		ret