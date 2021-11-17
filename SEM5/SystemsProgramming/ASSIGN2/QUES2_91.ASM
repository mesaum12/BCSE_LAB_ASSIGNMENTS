;Program to Implement Linear search.
include MACROS.asm
.model small
.stack 100h
.data
	msg1 db 10,13,"Enter size of array: $"
	msg2 db 10,13,"Enter elements of array: $"
	msg3 db 10,13,"Enter element to be searched: $"
	msg4 db 10,13,"The element is present at: $"
	msg5 db 10,13,"No such element is present ! $"
	arr dw 50 dup(?)
	s dw ?
.code
	main proc
		mov ax,@data
		mov ds,ax
		;input size
		printm msg1		
		dec_input
		;input elements
		printm msg2
		new_line
		mov s,bx
		lea si,arr
		mov cx,bx
		@array_input:
			pushall
			dec_input
			mov word ptr[si],bx
			popall
			inc si
			inc si
		loop @array_input
		; enter element to search
		printm msg3
		dec_input
		lea si,arr
		mov cx,s
		@linear_search:
			cmp bx,word ptr[si]
			je @found_word
			inc si
			inc si
		loop @linear_search
		;if not found
		printm msg5
		jmp @exit
		@found_word:
			printm msg4
			mov bx,s
			sub bx,cx
			inc bx
			dec_output
		@exit:
			exitp
	main endp
end main
