;Program to rename a file.
include MACROS.asm
.model small
.stack 100h
.data
	prev_name_of_file db "previous.txt", 0
	new_name_of_file db "new.txt", 0
	msg db 10,13,"File has been renamed successfully renamed $"
.code
	main proc
		mov ax, @data
		mov ds, ax
		mov es, ax
		lea dx,prev_name_of_file
		lea di,new_name_of_file
		mov ah,56h	;to rename file
		int 21h
		printm msg
		exitp	;exit
	main endp
end main
