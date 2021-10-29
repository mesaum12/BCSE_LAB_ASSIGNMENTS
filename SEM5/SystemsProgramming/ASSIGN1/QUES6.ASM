; take character from input and print it
.model small
.stack 100h
.data
        inp_msg  db "Enter a character: $"
        oup_msg  db 0dh,0ah,"The character to print: $"
.code
main proc
    mov ax, @data   ; Initialize ds to address
    mov ds, ax      ; of data segment
    lea dx, inp_msg  ; Get address of message
    mov ah, 09h     ; Display input string function
    int 21h         ; Display call
    mov ah, 01h     ; Read char function
    int 21h         ; Read call
    mov bl, al      ; Store value from accumulator
    lea dx, oup_msg  ; Get address of message
    mov ah, 09h     ; Display output string function
    int 21h         ; Call display
    mov ah, 02h     ; Write charachter to stdout
    mov dl, bl      ; Store value in dl
    int 21h         ; Call display
    mov ah, 4ch     ; Exit program
    int 21h         
main endp
end main
