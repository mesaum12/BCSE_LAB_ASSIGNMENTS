;program to display the name and title of the program taken as input
;from the user
.model small
.stack 100h

.data
prompt1 db "Enter the name of the student : $"
prompt2 db "Enter the name of the program : $"
studentname db 100 dup('$')
programtitle db 100 dup('$')
.code

main proc
mov ax,@data ;initialise the accumulator to the data segment
mov ds,ax    ;copy the address to the data segment

;print the prompt1 message to take the name as the input
lea dx,prompt1
mov ah,9h
int 21h

lea si,studentname;initialise the starting index with the student name

label1:
mov ah,1
int 21h
cmp al,13
je printstring1
mov [si],al
inc si
jmp label1

printstring1:
lea dx,studentname
mov ah,9
int 21h

mov dl,13
mov ah,2
int 21h
mov dl,10
mov ah,2
int 21h

lea dx,prompt2
mov ah,9
int 21h
lea si,programtitle

label2:
mov ah,1
int 21h
cmp al,13
je printstring2
mov [si],al
inc si
jmp label2

printstring2:
lea dx,programtitle
mov ah,9
int 21h


mov ah,4ch
int 21h
main endp
end main
