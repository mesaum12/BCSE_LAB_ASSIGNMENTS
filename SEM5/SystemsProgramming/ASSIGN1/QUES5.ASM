; Print Terminating message
.MODEL SMALL
.STACK 100H
.DATA
        Msg_to_print DB "Program Terminated...$"

.CODE
MAIN PROC
    MOV AX, @DATA    ;   Initialize DS to address
    MOV DS, AX       ;   of Data Segment
    LEA DX, Msg_to_print  ;   Load effective address
    MOV AH, 09H      ;   Display terminating message
    INT 21H          ;   Interrupt
    MOV DL, 10       ;   Display new Line
    MOV AH, 02H      ;   Display character to STDOUT
    INT 21H          ;   Interrupt
    MOV AH, 4CH      ;   DOS function: Exit program
    INT 21H          ;   Call DOS
MAIN ENDP
END MAIN
