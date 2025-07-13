bits 32 
global start        

extern exit               
import exit msvcrt.dll
extern printf
import printf msvcrt.dll
extern fopen
import fopen msvcrt.dll

;A text file is given. Read the content of the file, count the number of even digits and display the result on the screen. The name of text file is defined in the data segment.
segment data use32 class=data
    file_in db "input.txt",0
    fr db "r", 0 
    f dd 0
    count db 0
    n resd 1

; our code starts here
segment code use32 class=code
    start:
        mov ebx, count
        push fr
        push file_in
        call [fopen]
        add esp, 4*2
        test eax, eax
        jz afiseaza
        repeta:
            jpo next
            inc ebx
            next:
                push fr
                push file_in
                call [fopen]
                add esp, 4*2
                test eax, eax
        loop repeta
        afiseaza:
        push ebx
        call [printf]
        add esp, 4      
      
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
