bits 32 
global start        

; declare external functions needed by our program
extern exit          
import exit msvcrt.dll
extern printf 
import printf msvcrt.dll   

;Two natural numbers a and b (a, b: dword, defined in the data segment) are given. Calculate their sum and display the result in the following format: "<a> + <b> = <result>". Example: "1 + 2 = 3" The values will be displayed in decimal format (base 10) with sign.


segment data use32 class=data
    
    a dd 1
    b dd 2
    format db "%d + %d = %d", 0

; our code starts here
segment code use32 class=code
    start:
        mov eax, [a]
        add eax, [b]
        
        push eax 
        push dword [b]
        push dword [a]
        push dword format
        
        call [printf]
        add esp, 4*4
                
    
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
