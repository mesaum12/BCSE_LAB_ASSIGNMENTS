;loop until the user decides to quit from the program
.model small
.stack 100h
.data
    msg1 db "Hello , this is the interactive program with loops.. $"
    msg2 db 0dh,0ah,"You Entered 0, ThankYou  $"
    msg3 db 0dh,0ah,"Press 0 to exit. $"
    msg4 db 0dh,0ah,"Enter number: $"
.code
main proc 
    mov ax, @data	; Initialize DS to address
    mov ds, ax      ; of Data Segment
    lea dx, msg1    ; Load Effective Address of msg1
    mov ah, 09h     ; Display String function
    int 21h         ; Call Display
    lea dx, msg3    ; Load Effective Address of msg3
    mov ah, 09h     ; Display String function
    int 21h         ; Call Display
LOOP_LABEL:
	lea dx, msg4
	mov ah, 09h
	int 21h
    mov ah, 01h     ; Read char function
    int 21h         ; Read call
    cmp al, '0'
    jnz LOOP_LABEL

    lea dx, msg2    ; Get address of msg2
    mov ah, 09h     ; Display string function
    int 21h         ; Call display
    mov ah,4ch
    int 21h
main endp
end main
