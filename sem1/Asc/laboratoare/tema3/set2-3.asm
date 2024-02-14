bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    a db 4
    b dw 10
    c dd 8
    d dq -6

; our code starts here
;(b+b+d)-(c+a)=(10+10-6)-(8+4)=14-12=2
;a - byte, b - word, c - double word, d - qword - Signed representation
segment code use32 class=code
    start:
        mov ax, [b]
        add ax, ax
        cwde
        cdq         ;edx:eax=b+b=20
        mov ebx, [d]
        mov ecx, [d+4]
        add ebx, eax
        adc ecx, edx    ;ecx:ebx=b+b+d=14
        mov edx, [c]
        mov al, [a]
        cbw
        cwde           ;eax=a=4
        add eax, edx    ;eax=c+a=12
        cdq      ;edx:eax=0
        sub ebx, eax
        sub ecx, edx
        mov eax, ebx
        mov edx, ecx
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
