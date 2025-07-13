bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 5
    b db 4
    d dw 3

; our code starts here
segment code use32 class=code
    start:
        mov al, [a]
        mul al
        neg ax
        mov cx, ax
        mov al, [b]
        dec al
        mov dl, 2
        mul dl
        add ax, cx
        mov dx, [d]
        sub ax,dx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
