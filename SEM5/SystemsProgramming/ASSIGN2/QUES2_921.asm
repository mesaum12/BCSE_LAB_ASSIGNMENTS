;Program to implement binary search
include MACROS.asm
.model small
.stack 100h
.data
	inpmsg1 db 10,13,"Enter size of array: $"
	inpmsg2 db 10,13,"Enter elements of array in sorted order: $"
	inpmsg3 db 10,13,"Enter element to be searched: $"
	oupmsg1 db 10,13,"element found at: $"
	oupmsg2 db 10,13,"element not found $"
	arr dw 50 dup(?)
	s dw ?
	start dw ?
	stop dw ?
	min_idx dw ?
	temp dw ?
.code
	main proc
		mov ax,@data
		mov ds,ax
		;accept size
		printm inpmsg1
		dec_input
		;accept elements
		mov s,bx
		lea si,arr
		mov cx,bx
		printm inpmsg2
		new_line
		@array_input:
			pushall
			dec_input
			mov word ptr[si],bx
			popall
			inc si
			inc si
		loop @array_input
		call sort
		; enter element to search
		printm inpmsg3
		dec_input
		lea si,arr
		mov cx,s
		dec cx
		mov start,00h
		mov stop,cx
		;binary search
		@binary_search:
			;find out the middle index
			lea si,arr
			mov cx,stop
			add cx,start
			shr cx,1		;cx is the index for the middle element
			add si,cx		;si=si+cx
			add si,cx
			push bx
			push cx
			mov bx,cx
			pop cx
			pop bx
			space
			push bx
			push cx
			mov bx,word ptr[si]
			pop cx
			pop bx
			cmp bx,word ptr[si]
			je @found		; if middle element then found
			jg @greater
			;if less
			@lesser:
				dec cx
				mov stop,cx
				jmp @compare
			@greater:
				inc cx
				mov start,cx
			@compare:
				mov cx,stop
				cmp cx,start
		jge @binary_search
		;if not found
		printm oupmsg2
		jmp @exit
		@found:
			printm oupmsg1
			mov bx,cx
			inc bx
			dec_output
		@exit:
			exitp
	main endp
	sort proc
		;Selection sort used
		lea si,arr
		mov cx,s
		dec cx
		@outer_loop:
			mov dx,cx				; dx is the inner loop counter
			mov di,si
			inc di
			inc di
			mov min_idx,si
			push si
			@inner_loop:
				mov si,min_idx
				mov bx,word ptr[si]
				cmp word ptr[di],bx
				jge @incr
				; else set min_idx the elements
				mov min_idx,di
				@incr:
				inc di
				inc di
				dec dx
			jnz @inner_loop
			;swap
			pop si
			mov di,min_idx
			mov bx,word ptr[di]
			xchg word ptr[si],bx
			mov word ptr[di],bx
			inc si
			inc si
			push si
			push cx
			pop cx
			pop si
		loop @outer_loop
		ret
	sort endp
end main