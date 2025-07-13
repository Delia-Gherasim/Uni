bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
;d:1 2 3 4 7 6 5
segment data use32 class=data
    s1 db '1','2','3','4'
    s2 db '5','6','7'
    l1 equ $-s1
    l2 equ $-s2
    d times l1+l2 db 0
; Two byte strings S1 and S2 are given. Obtain the string D by concatenating the elements of S1 from the left hand side to the right hand side and the elements of S2 from the right hand side to the left hand side.
segment code use32 class=code
    start:
        mov ecx, l1
        mov esi, 0
        jecxz endfor
        repeta1:
            mov al, [s1+esi]
            mov [d+esi], al
            inc esi
        loop repeta1
        endfor
        mov ecx, l2
        mov esi, l2-1
        mov edi, 0
        jecxz sfarsit
        repeta2:
            mov al, [s2+esi]
            mov [d+edi], al
            inc edi
            dec esi        
        loop repeta2
        sfarsit:
        
        ;exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
