;File: escapeseqs.asm
;Project: CMSC 313 Project 2, Fall 2015
;Author: John Larson
;Date: 9/28/2015
;E-mail: larson3@umbc.edu
;This file contains the entirety of the escapeseqs.asm which will take
;in a user defined string and parse it for escape sequences.  Upon finding
;a \ it will check for a valid escape sequence or ASCII code and print
;the result, otherwise it will give an error message

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define BUFLEN 256
%define STRLEN 32


        SECTION .data                   ; initialized data section

msg1:   db "Enter string: "             ; user prompt
len1:   equ $-msg1                      ; length of first message

msg2:   db "Original: "                 ; original string label
len2:   equ $-msg2                      ; length of second message

msg3:   db "Convert:  "                 ; converted string label
len3:   equ $-msg3

msg4:   db "Error: unknown escape sequence \"       ; error message
len4:   equ $-msg4

msg5:	db "Error: octal value overflow in \"
len5:	equ $-msg5

msg6:	db 10
len6:	equ $-msg6

table:	db 92,-1,-1,-1,-1,7,8,-1,-1,-1,12,-1,-1,-1,-1,-1,-1,-1,10,-1,-1,-1,13,-1,9,-1,11,-1,-1,-1



        SECTION .bss                    ; uninitialized data section
buf:    resb BUFLEN                     ; buffer for read
newstr: resb BUFLEN                     ; converted string
rlen:   resb 4                          ; length
tempVal: resb 32					; value of char
octDigit: resb 4					; needed for octal analysis
oldString: resb 32


        SECTION .text                   ; Code section.
        global  _start                  ; let loader see entry point

_start: nop                             ; Entry point.
start:                                  ; address for gdb

        ; prompt user for input
        ;
        mov     eax, SYSCALL_WRITE      ; write function
        mov     ebx, STDOUT             ; Arg1: file descriptor
        mov     ecx, msg1               ; Arg2: addr of message
        mov     edx, len1               ; Arg3: length of message
        int     080h                    ; ask kernel to write

        ; read user input
        ;
        mov     eax, SYSCALL_READ       ; read function
        mov     ebx, STDIN              ; Arg 1: file descriptor
        mov     ecx, buf                ; Arg 2: address of buffer
        mov     edx, BUFLEN-1             ; Arg 3: buffer length
        int     080h
        ; error check
        ;
        mov     [rlen], eax             ; save length of string read
        cmp     eax, 0                  ; check if any chars read
        jg      read_OK                 ; >0 chars read = OK
        mov     eax, SYSCALL_WRITE      ; ow print error mesg
        mov     ebx, STDOUT
        mov     ecx, msg4
        mov     edx, len4
        int     080h
        jmp     exit                    ; skip over rest
read_OK:


        ; Loop for upper case conversion
        ; assuming rlen > 0
        ;
L1_init:
		mov 	byte[buf+eax],0			; adding a nul char to end of str
        mov     ecx, [rlen]             ; initialize count
        mov     esi, buf                ; point to start of buffer
        mov     edi, newstr             ; point to start of new string

L1_top:
        mov     al, [esi]               ; get a character
		cmp		al,0					;if null, terminate
		je		L1_end
		
		
		
        inc     esi           			; update source pointer
		cmp		al,"\"
		jne		L1_cont
		call	handle_ESC
		mov		al,[tempVal]
L1_cont:
        mov     [edi], al               ; store char in new string
		
        inc     edi                     ; update dest pointer
		
        jmp     L1_top                  ; loop to top if more chars
		


L1_end:


        ; print out user input for feedback
        ;
        mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg2
        mov     edx, len2
        int     080h

        mov     eax, SYSCALL_WRITE      ; write user input
        mov     ebx, STDOUT
        mov     ecx, buf
        mov     edx, [rlen]
        int     080h

        ; print out converted string
        ;
        mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg3
        mov     edx, len3
        int     080h

        mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, newstr
        mov     edx, [rlen]
        int     080h
		jmp 	exit
		
handle_ESC:

		mov 	al, [esi]
		mov		[oldString],al
	    inc     esi           			; update source pointer

		cmp 	al, "0"					;if lower than 0, jump to other
		jb		L1_notNum
		
		cmp		al, "8"					; lower than 8
		jb		L1_num					; then must be an octal number

		jmp		L1_notNum
		ret
		
L1_notNum:
		;check if in table

		cmp		al,"\"
		je		L1_table
		
		cmp		al, "a"					
		jb		L1_error
		
		cmp		al,"z"
		jb		L1_table
		jmp		L1_error			;if not in table, we give an error
		
		ret
		
L1_table:
	
				;getting the table value of the char
		
		mov		[tempVal],al

		mov		eax,[tempVal]		;we need this in eax, not al
		sub		eax,92				;getting the table value of the char
		mov 	bl,[table+ eax]	;finding the char on the table

		cmp		bl,-1
		je		L1_error
		mov		[tempVal],bl
		ret
L1_num:
		;loop three times, check if 8 and then check if whole number is
		;less than 255 dec.
		mov 	edx,0
		mov		ebx,0
		mov		ecx,0
		mov		[tempVal],ebx
		jmp		L1_octLoop
		
		ret
		

L1_octLoop:
		
		
		sub 	al,48					;first we get the real int value
		mov		[octDigit],al			;then move it into memory
		mov		eax, [tempVal]			;store the val in al
		mov 	ebx,8					;so we can do multiplication
		imul	ebx						;mult the val by 8
		mov		ebx,[octDigit]			;digit back to register
		add     eax,ebx					;add together
		mov		[tempVal],eax			;back to memory
		
		mov 	al, [esi]
		sub 	al,48	

		inc     ecx 						;counting iterations
		cmp 	ecx,3				;leaving the loop after 3 iterations
		je		L1_testSize
		
		cmp		al,7
		jbe		L1_preLoop

		jmp		L1_testSize
		ret

		
L1_preLoop:
		inc 	esi
		
		add		al,48
		
		mov		[oldString+ecx],al
		jmp		L1_octLoop
		
L1_testSize:
		
		mov		eax,[tempVal]
		cmp		eax,255
		jg		L1_sizeError

		ret
		

L1_error:

		mov		eax,92
		mov		[tempVal],eax


	    mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg4
        mov     edx, len4
        int     080h
		
		mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, oldString
        mov     edx, STRLEN
        int     080h
		
		mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, msg6
        mov     edx, len6
        int     080h
		
		ret
		
L1_sizeError:
		
		mov		eax,"\"
		mov		[tempVal],al
	    mov     eax, SYSCALL_WRITE      ; write message
        mov     ebx, STDOUT
        mov     ecx, msg5
        mov     edx, len5
        int     080h
		
		mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, oldString
        mov     edx, STRLEN
        int     080h
		
		mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, msg6
        mov     edx, len6
        int     080h

		ret
		
exit:   mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over