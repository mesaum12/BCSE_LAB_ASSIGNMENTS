; Add and Subtract two 16 bit numbers
include MACROS.asm
.model small
.stack 100h
.data
	msg1 db "Enter 1st number: $"
	msg2 db "Enter 2nd number: $"
	msg3 db "Their sum is: $"
	msg4 db "Their difference is: $"
	num1 dw ?
	num2 dw ?
.code
	main proc
		mov ax,@data
		mov ds,ax
		;input the first number 
		printm msg1
		hex_input
		mov num1,bx
		printm msg2
		hex_input
		mov num2,bx		
		;calculating sum
		printm msg3		
		mov cx,num1
		add bx,cx
		jnc display
		carry_disp:
			;display carry as 1 
			mov ah,02h
			mov dl,'1'
			int 21h
		display:
			hex_output
		;calculating difference
		new_line
		printm msg4		
		mov bx,num1
		mov cx,num2
		sub bx,cx		
		hex_output		
		exitp
	main endp
end main
