; check if second number is lesser than the first number
.model small
.stack 100h
.data
    num1  db  "Enter 1st number: $"
    num2  db  0dh,0ah,"Enter 2nd number: $"
    msg1  db  0dh,0ah,"Second number is not lesser.$"
    msg2  db  0dh,0ah,"Second number is lesser.$"
.code
main proc
    mov ax,@data    ;   Initialize DS to address
    mov ds,ax       ;   of Data Segment
	lea dx,num1     ;   Load effective address
	mov ah,09h		;   Display input string function
	int 21h         ;   Interrupt
	mov ah,01h      ;   Read char function
	int 21h			;   Read call
	mov bl,al		;   Store value from accumulator
	lea dx,num2		;   Load effective address
	mov ah,09h		;   Display input string function
	int 21h			;   Interrupt
	mov ah,01h		;   Read char function
	int 21h         ;   Interrupt
    sub al,bl		;	Subtract contents of bl from accumulator(calculate num2-num1)
    js LESS_LABEL          ;       Jump if sign flag set i.e. num2<num1
    lea dx, msg1    ; 	Get address of message
    mov ah, 09h     ; 	Display string function
    int 21h         ; 	Display call
    mov ah, 4ch     ; 	Exit program
    int 21h    
LESS_LABEL:
    lea dx, msg2    ; 	Get address of message
    mov ah, 09h     ; 	Display string function
    int 21h         ; 	Display call
    mov ah, 4ch     ; 	Exit program
    int 21h    
main endp
end main
