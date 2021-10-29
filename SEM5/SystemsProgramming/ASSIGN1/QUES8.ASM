; Find maximum and minimum of an Array
.model small
.stack 100h
.data
	linefeed      db 13,10,"$"
	len           db 8
        nums          db "4","3","2","9","1","3","5","9"
	msg1          db " is minimum$"
	msg2          db " is maximum$"
.code
main proc
    mov ax, @data           
    mov ds, ax              ; Set address of data segment    
    cmp len, 1              ; Length check of array
    jne not_single_elem     ; Jump if length >1
    mov dh, nums[0]         ; Move first element
    jmp disp                ; Unconditional JUMP
    
not_single_elem:
    mov dl, nums[0]         ; Get first element
    mov dh, nums[1]         ; Get second element
    cmp dl, dh              ; Compare
    jg initialise           ; Jump if greater    
    xchg dl, dh             ; Exchange DL,DH
    
initialise:                       
    mov cl, 1               ; Set counter
    mov di, 1               ; Set counter
    
findmin:
    inc di                  ; Increment Counter
    inc cl                  ; Increment Counter
    cmp cl, len             ; Compare with length
    je initialise2          ; Go to maximum finding loop if equal    
    mov al, nums[di]        ; Get current element    
    cmp al, dh              ; Compare al and dh
    jg findmin              ; Jump if greater
    mov dh, al              ; Move current to dh
    jmp findmin             ; Unconditional Jump

initialise2:
    mov cl, 1               ; Set counter for minimum
    mov di, 1               ; Set counter for minimum
    mov bl, nums[0]         ; Get First element
    mov bh, nums[1]         ; Get Second element
    cmp bl, bh              ; Compare
    jle findmax             ; Jump if less or equal    
    xchg bl, bh             ; Exchange BL,BH   
	
findmax:
    inc di                  ; Increment Counter
    inc cl                  ; Increment Counter
    cmp cl, len             ; Compare with length
    je disp                 ; Jump to result display if equal    
    mov al, nums[di]        ; Get current element
    cmp al, bh              ; Compare al and bh
    jl findmax              ; Jump if less
    mov bh, al              ; BH = AL
    jmp findmax             ; Unconditional Jump 
	
disp:
    mov dl,dh
    mov ah, 2               ; Result Display
    int 21h
    lea dx,msg1             ; Message print
    mov ah, 9
    int 21h
    call ins_line           ; New line print
    mov dl, bh
    mov ah, 2
    int 21h
    lea dx,msg2             ; Message print
    mov ah, 9
    int 21h
    mov  ax, 4c00h          ; Exit program
    int  21h
main endp

ins_line proc
    lea dx,linefeed         ; Subroutine for printing new line
    mov ah,9
    int 21h
    ret
ins_line endp
end
