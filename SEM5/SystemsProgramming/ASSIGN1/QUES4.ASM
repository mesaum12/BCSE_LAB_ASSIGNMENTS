.model small
.stack 256h
.data
	linefeed      db 13, 10, "$"
	len           db 8
        nums          db "46675368"
	msg1          db " is 2nd maximum$"
	msg2          db " is 2nd minimum$"
.code 	                    ; code segment
call main
mov  ax, 4c00h              ; Exit Program
int  21h  

main proc
    mov ax, @data           ; Set address to data segment
    mov ds, ax
    cmp len, 1              ; Check length of array
    jne SIZE_NOT_1          ; if length>1
    mov dl, nums[0]         ; else min max are first element
    mov bl, dl
    jmp disp    
    
SIZE_NOT_1:
    mov dl, nums[0]         ; dl = first element 
    mov dh, nums[1]         ; dh = second element
    cmp dl, dh              ; Compare
    jle initialise          ; jump if less or equal    
    xchg dl, dh             ; exchange dl dh
    
initialise:
    mov bl, dl              
    mov bh, dh
    mov cl, 1               ; Set Counter
    mov di, 1               ; Set Counter
    
nums_loop:
    inc di                  ; Increment Counter
    inc cl                  ; Increment Counter
    cmp cl, len             ; Compare
    je disp                 ; Jump to display if array traversed    
    mov al, nums[di]        ; Move current number   
    cmp al, dh              ; Compare
    jl maxi        			; Jump if less
    mov dl, dh
    mov dh, al    
    jmp maxi2      			; Unconditional jump
    
maxi:
    cmp al, dl              ; Compare al, dl
    jl maxi2       			; Jump if less
    mov dl, al              ; DL = AL
    
maxi2:
    cmp al, bl              ; Compare al, bl
    jg mini         		; Jump if greater
    mov bh, bl              ; BH = BL
    mov bl, al              ; BL = AL    
    jmp mini2       		; Unconditional Jump
    
mini:
    cmp al, bh              ; Compare al, bh
    jg mini2        		; jump if greater
    mov bh, al              ; BH = AL
    
mini2:
    jmp nums_loop           ; Unconditional Jump
    
disp:
    mov ah, 2   			; Print result
    int 21h   
    lea dx,msg1             ; Message print
    mov ah, 9
    int 21h
    call ins_line   
    mov dl, bh
    mov ah, 2
    int 21h  
    lea dx,msg2             ; Message print
    mov ah, 9
    int 21h
    ret
main endp

ins_line proc
    lea dx,linefeed 		; New Line printer
    mov ah,9
    int 21h
    ret
ins_line endp
end
