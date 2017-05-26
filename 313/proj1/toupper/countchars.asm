;File: countchar.asm
;Project: CMSC 313 Project 1, Fall 2015
;Author: John Larson
;Date: 9/21/2015
;E-mail: larson3@umbc.edu
;This file contains the entirety of the countchars.asm file which counts
;the total number of letters, numbers and other characters in a user 
;entered string.

%define STDIN 0
%define STDOUT 1
%define SYSCALL_EXIT  1
%define SYSCALL_READ  3
%define SYSCALL_WRITE 4
%define BUFLEN 256


        SECTION .data                   ; initialized data section

msg1:   db "Text to be analyzed: "             ; user prompt
len1:   equ $-msg1                      ; length of first message

msg2:   db "You entered: "                 ; original string label
len2:   equ $-msg2                      ; length of second message

msg3:   db "There were "                 ; converted string label
len3:   equ $-msg3

msg4:   db 10, "Read error", 10         ; error message
len4:   equ $-msg4

msg5:	db " alphabetic characters.", 10 ; the next three msgs are
len5: 	equ $-msg5						 ; the second part of our output

msg6:	db " numeric characters.", 10
len6: 	equ $-msg6

msg7:	db " other characters.", 10
len7: 	equ $-msg7

        SECTION .bss                    ; uninitialized data section
buf:    resb BUFLEN                     ; buffer for read
newstr: resb BUFLEN                     ; converted string
rlen:   resb 4                          ; length
newLen: resb BUFLEN
alphaCount: resb BUFLEN
numCount: resb BUFLEN
otherCount: resb BUFLEN


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
        mov     edx, BUFLEN             ; Arg 3: buffer length
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
        mov     ch, [rlen]             ; initialize count
        mov     esi, buf                ; point to start of buffer
        mov     edi, newstr             ; point to start of new string
		
L1_temp:
		mov		bl, 0					; put 0 into bl - characters
		mov		cl, 0					; put 0 into cl - numeric
		mov		dl, 0					; put 0 into dl - other
L1_top:
		mov     al, [esi]               ; get a character
		cmp		al, 10					; skip counting if newline
		je 		L1_cont
		
		cmp 	al, "0"					;if lower than 0, jump to other
		jb		L1_other
		
		cmp		al, "9"					; lower than 9 AND higher than 080h
		jb		L1_num					; then must be a number
		
		cmp		al, "A"					; theres some symbols between 9 and
		jb		L1_other				; A
		
		cmp		al, "Z"					; but it's a cap letter if it is
		jb		L1_alpha				; higher than A but lower than Z
		
		cmp		al, "a"					; see above logic
		jb		L1_other
		
		cmp		al,"z"
		jb		L1_alpha
		jmp		L1_other				; the rest of the possibilities are others
		

L1_alpha:
	    add     bl, 1               	;adding one for every iteration
        inc     esi  
		jmp 	L1_cont
L1_num:
		add     cl, 1               	;adding one for every iteration
        inc     esi  
		jmp 	L1_cont
L1_other:
	    add     dl, 1               	;adding one for every iteration
        inc     esi  
		jmp 	L1_cont
L1_cont:

        dec     ch                    ; update char count
        jnz     L1_top                  ; loop to top if more chars
L1_end:

		mov 	[alphaCount], bl		; moving from registers to memory
		mov		[numCount],cl			; so that we can use registers to
		mov		[otherCount],dl			; print
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

        ; print out alpha count
        ;
		mov 	bl,[alphaCount]
		add		bl, "0"
		mov		[edi], bl
        mov     eax, SYSCALL_WRITE      ; part 1 of message
        mov     ebx, STDOUT
        mov     ecx, msg3
        mov     edx, len3
        int     080h

		
        mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, newstr
        mov     edx, [rlen]
        int     080h

	    mov     eax, SYSCALL_WRITE      ; write second part of message
        mov     ebx, STDOUT
        mov     ecx, msg5
        mov     edx, len5
        int     080h
		
		        ; print out number count
        ;
		mov 	cl,[numCount]
		add		cl, "0"
		mov		[edi], cl
        mov     eax, SYSCALL_WRITE      ; part 1 of message
        mov     ebx, STDOUT
        mov     ecx, msg3
        mov     edx, len3
        int     080h

		
        mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, newstr
        mov     edx, [rlen]
        int     080h

	    mov     eax, SYSCALL_WRITE      ; write second part of message
        mov     ebx, STDOUT
        mov     ecx, msg6
        mov     edx, len6
        int     080h

				        ; print out other count
        ;
		mov 	dl,[otherCount]
		add		dl, "0"
		mov		[edi], dl
        mov     eax, SYSCALL_WRITE      ; part 1 of message
        mov     ebx, STDOUT
        mov     ecx, msg3
        mov     edx, len3
        int     080h

		
        mov     eax, SYSCALL_WRITE      ; write out string
        mov     ebx, STDOUT
        mov     ecx, newstr
        mov     edx, [rlen]
        int     080h

	    mov     eax, SYSCALL_WRITE      ; write second part of message
        mov     ebx, STDOUT
        mov     ecx, msg7
        mov     edx, len7
        int     080h
		
        ; final exit
        ;
exit:   mov     eax, SYSCALL_EXIT       ; exit function
        mov     ebx, 0                  ; exit code, 0=normal
        int     080h                    ; ask kernel to take over
