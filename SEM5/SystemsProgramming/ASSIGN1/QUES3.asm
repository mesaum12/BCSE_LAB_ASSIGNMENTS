;write and test a masm program to add two hexadecimal numbers.

.model small
.stack 100h
.data 
    msg1 db 13,10,"Enter the 1st hexadecimal number: $"
    msg2 db 13,10,"Enter the 2nd hexadecimal number: $"
    msg3 db 13,10,"Result of addition: $"

.code
   main proc
          mov ax,@data             ;for moving data 
          mov ds,ax         	   ;to data segment
          xor bx,bx                ;initially setting bx value is equal to 0
          mov cl,4               
          lea dx, msg1             ;show msg1
          mov ah, 9
          int 21h
          mov ah,1                 ;for taking input
          int 21h
           
      input1:
          cmp al,0dh               ;check if the pressed key is 'enter' or not(Ascii 13)
          je line1                 ;if it is equal to 'enter' then stop taking first value         
          cmp al,39h               ;check if the input is char or digit(Ascii value of 9 is 39h)
          jg char1          
          and al,0fh               ;if it is digit then convert it's ascii value to real value by masking
          jmp shift1
          
      char1:                       ;if it is char then subtract 37h from it to find it's real value
          sub al,37h
       
      shift1:
          shl bx, cl
          or  bl,al                ;making 'or' will add the current value with previous value         
          int 21h
          jmp input1

      line1:
          lea dx, msg2             ;show msg2
          mov ah, 9
          int 21h
          xor dx,dx                ;setting dx value zero
          mov ah,1
          int 21h
    
      input2:
          cmp al,0dh               ;check if the pressed key is 'enter' or not
          je line2                 ;if it is equal to 'enter' then stop taking first value        
          cmp al,39h               ;compare if the input is char or digit
          jg char2          
          and al,0fh               ;if it is digit then convert it's ascii value to real value by masking
          jmp shift2
          
      char2:                       ;if it is char then subtract 37h from it to find it's real value
          sub al,37h
       
      shift2:
          shl dx, cl
          or  dl,al                ;making 'or' will add the current value with previous value           
          int 21h
          jmp input2

      line2:
          xor cx,cx
          mov cx,dx
          mov dh,16
      
      sum:
          add bx,cx                ;add two number which are stored in bx and cs register
          jc overflow              ;if the register is overflowed then print an extra 1
          mov cl, 4      
          lea dx, msg3             ;show msg3
          mov ah, 9
          int 21h

      output:                      ;level for printing their sum          
          mov ch,bh
          shr ch, cl
          and ch,0fh
          cmp ch,10                ;convert decimal to binary
          add ch,'0'
          cmp ch,':'
          jl oup
          add ch,7

      oup:
		  mov dl,ch
          mov ah,2
          int 21h
          mov ch,bh
          and ch,0fh
          cmp ch,10
          add ch,'0'
          cmp ch,':'
          jl oup1
          add ch,7

      oup1:
		  mov dl,ch
          mov ah,2
          int 21h

          mov ch,bl
          shr ch, cl
          and ch,0fh
          cmp ch,10
          add ch,'0'
          cmp ch,':'
          jl oup2
          add ch,7

      oup2:
		  mov dl,ch
          mov ah,2
          int 21h
          mov ch,bl
          and ch,0fh
          cmp ch,10
          add ch,'0'
          cmp ch,':'
          jl oup3
          add ch,7

      oup3:
		  mov dl,ch
          mov ah,2
          int 21h
          jmp exit

      overflow:                      ;level for printing overflowed 1
          mov dl,'1'
          mov ah,2
          int 21h
          jmp output
      
      exit:
          mov ah, 4ch                ;return control to dos
          int 21h
        
    main endp
end main