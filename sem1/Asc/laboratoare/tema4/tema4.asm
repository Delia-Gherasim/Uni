bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a dw 0111011101010111b
    b dw 1001101110111110b
    c dw 0

; our code starts here
;Given the words A and B, compute the doubleword C as follows:
;the bits 0-2 of C are the same as the bits 12-14 of A
;the bits 3-8 of C are the same as the bits 0-5 of B
;the bits 9-15 of C are the same as the bits 3-9 of A
;the bits 16-31 of C are the same as the bits of A
segment code use32 class=code
    start:
        mov bx, 0
        mov ax, [a]
        and ax, 0111000000000000b
        mov cl, 12
        ror ax, cl
        or bx, ax
    
        mov ax, [b]
        and ax, 0000000000111111b
        mov cl, 3
        rol ax, cl
        or bx, ax
        
        mov ax, [a]
        and ax, 0000001111111000b
        mov cl, 6
        rol ax, cl
        or bx, ax
        
        mov cx, [a]
        
        mov ax, bx
        mov dx, cx
        
        push dx
        push ax
        pop eax
        
        mov [c], eax
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
