; Print Student Name and program title
.MODEL SMALL
.STACK 100H
.DATA
       STUDENTNAME DB "Saurabh Mukherjee$"
        PROGTITLE DB "QUES1.asm$"
.CODE
MAIN PROC
    MOV AX, @DATA    ;   Initialize DS to address
    MOV DS, AX       ;   of Data Segment
    LEA DX, STUDENTNAME    ;   Load effective address
    MOV AH, 09H      ;   Display input string function
    INT 21H          ;   Display message
    MOV DL, 10       ;   Display new Line
    MOV AH, 02H      ;   Display character to STDOUT
    INT 21H          ;   Display message
    LEA DX, PROGTITLE;   Load effective address
    MOV AH, 09H      ;   Display output string function
    INT 21H          ;   Display message
    MOV AH, 4CH      ;   DOS function: Exit program
    INT 21H          ;   Call DOS
MAIN ENDP
END MAIN
