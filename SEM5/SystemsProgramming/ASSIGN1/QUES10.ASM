;Printing the character from A to Z on the screen
.model small
.stack 100h
.data
    msg db "The alphabets needed to be printed are: $"
.code
main proc 
    mov ax, @data   ; 	Initialize DS to address
    mov ds, ax      ; 	of Data Segment
    lea dx, msg     ;   Load effective address of msg
    mov ah, 09h     ;   Write string to STDOUT
    int 21h         ;   Call Display
    mov bl,65       ;   Ascii value of A is 65
    mov cl,26       ;   Counter set to 26

LOOP_LABEL:
    mov ah,02h      ;   Write charachter to STDOUT
    mov dl,bl       ;   Store in DL for display
    inc bl          ;   Increment BL
    dec cl          ;   Decrement Counter
    int 21h         ;   Call Display
    mov dl,32       ;   STORING THE ASCII OF SPACE IN DL TO PRINT 
    int 21h         ;   Call Display
    jnz LOOP_LABEL     ;   Jump to print if not zero 
	mov ah,4ch      ;   Exit code
	int 21h              
main endp
end main
