;Program to print pairs of even numbers where the sum of the numbers in each pair is 100.
include MACROS.asm
.model small
.stack 100h
.data
	oupmsg db "Even pairs with sum 100: $"
	tempb dw ?
	tempc dw ?
.code
	main proc
		mov ax,@data
		mov ds,ax
		printm oupmsg
		new_line
		mov bx,0
		mov cx,100
		@print_loop:
			mov tempb,bx
			mov tempc,cx
			dec_output
			space
			mov bx,tempc
			dec_output
			space
			space
			mov bx,tempb
			mov cx,tempc
			inc bx
			inc bx
			dec cx
			dec cx
			cmp bx,50
		jle @print_loop
		exitp
	main endp
end main