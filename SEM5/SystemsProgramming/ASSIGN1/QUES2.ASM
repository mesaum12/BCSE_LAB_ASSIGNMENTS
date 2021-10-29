; Convert character from uppercase to lowercase
;We are ORing the 6th bit to convert the ascii code here 
.model small
.stack 100h
.data
	inp db "Enter a uppercase character: $"
	oup db 0dh,0ah,"In lowercase: $"
.code
main proc
    mov ax, @data   ; Initialize ds to address
    mov ds, ax      ; of data segment
    lea dx, inp     ; Get address of message
    mov ah, 09h     ; Display input string function
    int 21h         ; Display call
    mov ah, 01h     ; Read char function
    int 21h         ; Read call
    mov bl, al      ; Store value from accumulator
    lea dx, oup     ; Get address of message
    mov ah, 09h     ; Display output string function
    int 21h         ; Display call
    or bl, 20h      ; Make 6th bit 1(Add 32 if uppercase and ignore if lowercase)
    mov ah, 2       ; Write character to stdout
    mov dl, bl      ; Store value in dl
    int 21h         ; Call display
    mov ah, 4ch     ; Exit program
    int 21h         
main endp
end main
