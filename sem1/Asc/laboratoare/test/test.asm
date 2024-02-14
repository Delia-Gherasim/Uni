bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fwrite, fclose, printf, scanf, fscanf              ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll
import fread msvcrt.dll
import fwrite msvcrt.dll
import fclose msvcrt.dll   
import printf msvcrt.dll
import fscanf msvcrt.dll
import scanf msvcrt.dll             ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; Se citeste de la tastatura un nume de fisier input.txt si un caracter c. Fisierul input.txt contine cuvinte separate prin spatiu. Sa se scrie in fisierul output.txt doar cuvintele in care apare caracterul c citit pe ultima pozitie (adica apare ca ultima litera din cuvant).
segment data use32 class=data
    fileformat db "input file name ", 0
    readc db "c= ", 0
    format db "%d", 0
    file_in db "%s", 0
    file_out db "output.txt", 0
    read db 'r', 0
    write db 'w', 0
    c resb 2
    cuvant db "%s", 0
    text resb 20
    filedescrin dd 0
    filedescrout dd 0
    cuv resb 20
    
    

; our code starts here
segment code use32 class=code
    start: 
        push dword fileformat
        call [printf]
        add esp, 4*1
        
        push dword text
        push dword file_in
        call [scanf]
        add esp, 4*1
        
        push dword readc
        call [printf]
        add esp, 4
        
        push dword c
        push dword format
        call [scanf]
        add esp, 4*2
        
        push dword read
        push dword file_in
        call [fopen]
        add esp, 4*2
        
        mov [filedescrin], eax
        cmp eax, 0
        je end
        
        repeta:
            ;push dword [filedescrin]
            ;push dword 1
            ;push dword 1
            ;push dword cuvant
            ;
            ;
            ;call [fread]
            ;add esp, 4*4
            ;cmp eax, 0
            ;je end
            
            push dword [filedescrin]
            push cuvant
            push cuv
            call [fscanf]
            add esp, 4*3
            cmp eax, 0
            je end
            
            mov ax, cuv
            cmp al, [c]
            jne nu_scrie
            
            push dword write
            push dword file_out
            call [fopen]
            add esp, 4*2
            mov [filedescrout], eax
            cmp eax, 0
            je end
            push dword [filedescrout]
            push dword 1
            push dword 1
            push dword cuvant
            call [fwrite]
            add esp, 4*4
            
           nu_scrie:
           jmp repeta
            
                
        end:
            push dword [filedescrin]
            call [fclose]
            add esp, 4*1
            
            push dword [filedescrout]
            call [fclose]
            add esp, 4*1
            
            push    dword 0      ; push the parameter for exit onto the stack
            call    [exit]       ; call exit to terminate the program
