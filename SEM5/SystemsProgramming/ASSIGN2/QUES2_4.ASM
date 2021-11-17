;Program to multiply two numbers(done for 8 bit)
include MACROS.asm
.model small
.stack 100h
.data
	msg1 db "Enter 1st number: $"
	msg2 db "Enter 2nd number: $"
      msg3 db "The product of the two numbers : $"
	num1 db ?
	num2 db ?
.code
	main proc
		mov ax,@data
		mov ds,ax
		xor bh,bh
		;input prompt
		printm msg1
		dec_input
		mov num1,bl
		xor bh,bh
		printm msg2
		dec_input
		mov num2,bl
		xor bh,bh
		xor ah,ah
		mov al,num1
		mul bx		
		mov bx,ax
		printm msg3
		dec_output
		exitp
	main endp
end main
