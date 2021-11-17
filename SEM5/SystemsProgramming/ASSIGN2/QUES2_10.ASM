;Program to print prime numbers between 1 to 100
include MACROS.asm
.model small
.stack 100h
.data
	msg db "The prime numbers from 1 to 100 are: $"
	num db ?
.code
	main proc 
		mov ax,@data
		mov ds,ax
		printm msg
		new_line 
		mov cl,02h
		start:	
			mov num,cl
			mov al,cl
			mov bl,01h      ; the dividing starts from 2, hence bh is compared to 02h
			mov dx,0000h    ; to avoid divide overflow error
			mov ah,00h      ; to avoid divide overflow error
			mov bh,00h

			;loop to check for prime no
			l1:
				div bl
				cmp ah,00h      ; remainder is compared with 00h (ah)
				jne next
				inc bh          ; bh is incremented if the number is divisible by current value of bl
				next:
					cmp bh,02h ; if bh > 02h, there is no need to proceed, it is not a prime
					je false        ; the number is non_prime
					inc bl          ; increment bl
					mov ax,0000h    ; to avoid divide overflow error
					mov dx,0000h    ; to avoid divide overflow error
					mov al,cl      ; move the default no to al
					cmp bl,cl      ; run the loop until bl matches number. i.e, run loop x no of times, where x is the number given
					jne l1          ; jump to check again with incremented value of bl

			;to display the given number is a prime no
			true: 
				mov ch,00h 
				mov bx,cx
				dec_output
				space
			false: 
				mov cl,num
				inc cl
				cmp cl,64h
				jne start
		exitp
	main endp
end main
