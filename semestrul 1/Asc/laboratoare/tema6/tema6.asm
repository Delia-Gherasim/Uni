bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

;An array of doublewords, where each doubleword contains 2 values on a word (unpacked, so each nibble is preceded by a 0) is given. Write an asm program to create a new array of bytes which contain those values (packed on a single byte), arranged in an ascending manner in memory, these being considered signed numbers.

segment data use32 class=data
    a1 dd 0702090Ah, 0B0C0304h, 05060108h
    l equ ($-a1)/4 ;lenght in doublewords
    a2 times l dw 0
    a3 times l dw 0
    zece db 10
; our code starts here
segment code use32 class=code
    start:
        cld ; df=0 left to right
        mov ecx, l
        mov edi, 0
        mov esi, a1
        repeta1:
            lodsw   ;ax will have the low word of the current dword
                    ;ax=090a
            mov bx, ax
            mov ah, 0
            div byte[zece]  ;obtains the last digit in ah
            mov dl, ah  ;dl=a
            mov al, bh  ;al=09
            idiv byte[zece]  ;ah=9
            mov al, 10
            imul ah ;ax=90
            mov dh, 0
            add ax, dx  ;ax=9a
            mov cx, ax
            
            lodsw   ;ax =high word
                    ;ax=0702
                    ;ah=07 al=02
            mov bx, ax
            mov ah, 0
            div byte[zece]  ;obtains the last digit in ah
            mov dl, ah  ;dl=2
            mov al, bh  ;al=07
            idiv byte[zece]  ;ah=7
            mov al, 10
            imul ah ;ax=70
            mov dh, 0
            add ah, dl  ;ax=72
            
            mov [a2+edi], ax
            inc edi
            mov [a2+edi], cx

        loop repeta1 
        
        mov esi, 0
        mov edi, 0
        cld
        mov ecx, l
        jecxz sfarsit
        repeta2:
            mov ax, [a2+edi]
            mov esi, 0
            mov edx, ecx
            mov ecx, l
            jecxz back
            for:
                mov bx, [a2+esi]
                cmp ax, bx
                jl switch
                switch:
                    mov [a2+edi], bx
                    mov [a2+esi], ax
                inc esi
            loop for
            back:
            mov ecx, edx
            inc edi
        loop repeta2
        
        sfarsit:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
