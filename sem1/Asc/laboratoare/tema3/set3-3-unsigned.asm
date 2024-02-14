bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 0
    b db 2
    c dd 10
    d db 5
    x dq 19

; (8-a*b*100+c)/d+x=(8-0+10)/5+19=22
; a,b,d-byte; c-doubleword; x-qword
segment code use32 class=code
    start:
        mov al, [a] 
        mov bl, [b]
        mul bl          
        mov bx, 100
        mul bx  
        push dx
        push ax
        pop eax
        mov ebx, eax
        mov eax, 8
        sub eax, ebx
        mov ebx, [c]
        add eax, ebx
        mov bl, [d]
        mov bh, 0
        div bx      
        mov dx, 0
        push dx
        push ax
        pop eax
        mov edx, 0  
        mov ebx, [x]
        mov ecx, [x+4]
        add eax, ebx
        adc edx, ecx
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
