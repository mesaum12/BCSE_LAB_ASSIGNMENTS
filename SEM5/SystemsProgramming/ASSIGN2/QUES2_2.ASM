;Program to Convert a Binary digit to Decimal and vice versa
include MACROS.asm
.model small
.stack 100h
.data
	msg1 db "Enter the binary number: $"
	msg2 db "Enter the decimal number: $"
	msg3 db "The corresponding decimal number: $"
	msg4 db "The corresponding binary number: $"
.code
	main proc
		mov ax,@data
		mov ds,ax
		;binary to decimal conversion
		;input the binary number
		printm msg1
		bin_input		
		;output the corresponding decimal number
           printm msg3
 		dec_output		
		new_line
		;decimal to binary
		;input the decimal number
           printm msg2
		dec_input		
		;output
		printm msg4
 		bin_output
		exitp
	main endp
end main
