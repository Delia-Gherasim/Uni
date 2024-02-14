bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 3
    b dw 9
    c dd 10
    d dq 20
;(c+d)-(a+d)+b=10+20-(3+20)+9=30-23+9=16
; our code starts here
segment code use32 class=code
    start:
        
        mov ebx, [c]
        mov ecx, 0
        mov eax, [d]
        mov edx, [d+4]
        add ecx, edx    
        add ebx, eax    
        mov al, [a]     
        mov ah, 0       
        mov dx, 0
        push dx
        push ax
        pop eax
        mov edx, 0
        add eax, [d]
        add edx, [d+4]
        sub ecx, edx
        sub ebx, eax
        mov ax, [b]
        mov dx, 0
        push dx
        push ax
        pop eax
        mov edx, 0
        add eax, ebx
        add ecx, edx
        
        
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
