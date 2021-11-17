;Program to Print Fibonacci series up to 10 terms
include MACROS.asm
.model small
.stack 100h
.data
	msg db "The fibonacci series upto 10 terms is: $"
	f1 dw 1
	f2 dw 1
	f3 dw ?
.code
	main proc
		mov ax,@data
		mov ds,ax
		mov bx,1
		mov dx,1
		printm msg
		new_line
		pushall
		dec_output
		space
		popall
		pushall
		dec_output
		space
		popall
		mov bx,1
		mov dx,1
		mov cx,8
		@looping:
			mov f1,bx	
			mov f2,dx
			add bx,dx
			mov f3,bx	;f3=f1+f2
			pushall
			dec_output
			space
			popall
			mov bx,f2	;f1=f2
			mov dx,f3	;f2=f3
		loop @looping
		exitp
	main endp
end main
