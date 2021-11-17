;Program to divide a 16 bit number by a 8 bit number.
include MACROS.asm
.model small
.stack 100h
.data
        msg1 db 10,13,"Enter a 16-bit number: $"
        msg2 db 10,13,"Enter a 8-bit number: $"
        msg3 db 10,13,"The quotient is : $"
        msg4 db 10,13,"The remainder is : $"
	num1 dw ?
.code
	main proc
		mov ax,@data
		mov ds,ax
		;input
           printm msg1
		hex_input
		mov num1,bx
           printm msg2
		hex_input
		mov ax,num1
		xor dx,dx
		div bx
		;output
		mov bx,ax
		mov num1,dx
           printm msg3
		pushall
		hex_output
		popall
		mov bx,num1
           printm msg4
		pushall
		hex_output
		popall
		exitp
	main endp
end main
