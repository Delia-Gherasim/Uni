bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 1
    b db 2
    c dd 10
    d db 5
    x dq 19

; (8-a*b*100+c)/d+x=(8-200+10)/5+19=-182/5+19=-36+19=-17
; a,b,d-byte; c-doubleword; x-qword
; our code starts here
segment code use32 class=code
    start:
        mov al, [a]
        imul byte [b]    ;ax=a*b
        mov bx, 100
        imul bx    ;dx:ax=a*b*100
        mov cx, 0
        mov bx, 8
        sub bx, ax    ;cx:bx=8-a*b*100+c
        sbb cx, dx
        add bx, [c]
        adc cx, [c+2]
        mov dx, cx
        mov ax, bx
        mov bl, [d]
        cbw
        idiv bx
        cwde
        mov edx, 0
        mov ebx, [x]
        mov ecx, [x+4]
        add eax, ebx
        adc edx, ecx
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
