; Print.s
; Student names: change this to your names or look very silly
; Last modification date: change this to the last modification date or look very silly
; Runs on LM4F120 or TM4C123
; EE319K lab 7 device driver for any LCD
;
; As part of Lab 7, students need to implement these LCD_OutDec and LCD_OutFix
; This driver assumes two low-level LCD functions
; ST7735_OutChar   outputs a single 8-bit ASCII character
; ST7735_OutString outputs a null-terminated string 	

	
    IMPORT   ST7735_OutChar
    IMPORT   ST7735_OutString
    EXPORT   LCD_OutDec
    EXPORT   LCD_OutFix

    AREA    |.text|, CODE, READONLY, ALIGN=2
    THUMB
	
INVALID	DCB "*.***"
	DCB    0X00
DOT  DCB    "."
	DCB    0X00
ZERO	DCB "0.000"
	DCB    0X00
ONE	DCB "0.00"
	DCB		0X00
TWO	DCB "0.0"
	DCB		0X00
THREE	DCB "0."
	DCB		0X00
LARGESTNUM   DCD 	0x3B9ACA00
	
  

;-----------------------LCD_OutDec-----------------------
; Output a 32-bit number in unsigned decimal format
; Input: R0 (call by value) 32-bit unsigned number
; Output: none
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutDec
	PUSH {R4-R12, LR}
	MOV R4, #10
	MOV R6, R0
	LDR R5, =LARGESTNUM
	LDR R5, [R5]
	PUSH{R4-R7}
FIRST_DIGIT_FIND
	UDIV R5,R5, R4				;R5 DIVIDOR 1000000, 100000, 1000, 100, 10, 1, 0
	CMP R5, #0					;R4 = 10
	BEQ OUT_ZERO				; R6 DATA
	UDIV R0, R6, R5				
	CMP R0, #0
	BEQ FIRST_DIGIT_FIND
	STR R5, [SP, #4]
	MUL R7, R5, R0
	SUB R6,R6,R7
	STR R6, [SP, #8]
	ADD R0, R0, #0x30
	BL ST7735_OutChar
PRINT_DEC
			; PRINTS OUT FIRST CHAR
	LDR R5, [SP, #4]
	LDR R6, [SP, #8]
	UDIV R5,R5, R4				;R1 DIVIDOR 1000000, 100000, 1000, 100, 10, 1, 0
	STR R5, [SP, #4]
	CMP R5, #0					;R2 = 10
	BEQ DONE_DEC				; R3 DIGIT BEING OUTPUTED
	UDIV R0, R6, R5				; R4 DATA
	MUL R7, R5, R0
	SUB R6,R6,R7
	STR R6, [SP, #8]
	ADD R0, R0, #0x30
	BL ST7735_OutChar
	B PRINT_DEC
	
OUT_ZERO
	MOV R0, #0x30
	BL ST7735_OutChar
	B DONE_DEC
	
DONE_DEC	
		POP {R4-R7}
		POP {R4-R12, LR}
      BX  LR
;* * * * * * * * End of LCD_OutDec * * * * * * * *

; -----------------------LCD _OutFix----------------------
; Output characters to LCD display in fixed-point format
; unsigned decimal, resolution 0.001, range 0.000 to 9.999
; Inputs:  R0 is an unsigned 32-bit number
; Outputs: none
; E.g., R0=0,    then output "0.000 "
;       R0=3,    then output "0.003 "
;       R0=89,   then output "0.089 "
;       R0=123,  then output "0.123 "
;       R0=9999, then output "9.999 "
;       R0>9999, then output "*.*** "
; Invariables: This function must not permanently modify registers R4 to R11
LCD_OutFix
	PUSH {R4-R12, LR}
	MOV R1, #9999		;CHECKING FOR NUMBER GREATER THAN 9999
	CMP R0, R1
	BLS FIX_LOOP
INVALID_OUT
	LDR R0, =INVALID
	BL ST7735_OutString
	
	POP {R4-R12, LR}
	BX LR
	
FIX_LOOP	
  MOV R4, #10
	MOV R6, R0
	MOV R5, #10000
	PUSH{R4-R7}
FIRST_DIGIT_FIND_FIX
	UDIV R5,R5, R4				;R5 DIVIDOR 1000000, 100000, 1000, 100, 10, 1, 0
	CMP R5, #0					;R4 = 10
	BEQ OUT_ZERO_FIX				; R6 DATA
	UDIV R0, R6, R5				
	CMP R0, #0
	BEQ FIRST_DIGIT_FIND_FIX
	STR R5, [SP, #4]
	MUL R7, R5, R0
	SUB R6,R6,R7
	STR R6, [SP, #8]
	ADD R0, R0, #0x30
	MOV R11, R0
	
	
PRINT_FIX1
			; PRINTS OUT FIRST CHAR
	LDR R5, [SP, #4]
	LDR R6, [SP, #8]
	UDIV R5,R5, R4				;R1 DIVIDOR 1000000, 100000, 1000, 100, 10, 1, 0
	STR R5, [SP, #4]
	CMP R5, #0					;R2 = 10
	BEQ DONE_FIX1			; R3 DIGIT BEING OUTPUTED
	UDIV R0, R6, R5				; R4 DATA
	MUL R7, R5, R0
	SUB R6,R6,R7
	STR R6, [SP, #8]
	ADD R0, R0, #0x30

	MOV R10, R0
	LDR R5, [SP, #4]
	LDR R6, [SP, #8]
	UDIV R5,R5, R4				;R1 DIVIDOR 1000000, 100000, 1000, 100, 10, 1, 0
	STR R5, [SP, #4]
	CMP R5, #0					;R2 = 10
	BEQ DONE_FIX2			; R3 DIGIT BEING OUTPUTED
	UDIV R0, R6, R5				; R4 DATA
	MUL R7, R5, R0
	SUB R6,R6,R7
	STR R6, [SP, #8]
	ADD R0, R0, #0x30
	
	MOV R9, R0
	LDR R5, [SP, #4]
	LDR R6, [SP, #8]
	UDIV R5,R5, R4				;R1 DIVIDOR 1000000, 100000, 1000, 100, 10, 1, 0
	STR R5, [SP, #4]
	CMP R5, #0					;R2 = 10
	BEQ DONE_FIX3			; R3 DIGIT BEING OUTPUTED
	UDIV R0, R6, R5				; R4 DATA
	MUL R7, R5, R0
	SUB R6,R6,R7
	STR R6, [SP, #8]
	ADD R0, R0, #0x30
	
	MOV R8, R0
	LDR R5, [SP, #4]
	LDR R6, [SP, #8]
	UDIV R5,R5, R4				;R1 DIVIDOR 1000000, 100000, 1000, 100, 10, 1, 0
	STR R5, [SP, #4]
	CMP R5, #0					;R2 = 10
	B DONE_FIX4			; R3 DIGIT BEING OUTPUTED
	
	
OUT_ZERO_FIX
	LDR R0, =ZERO
	BL ST7735_OutString
	B DONE_FIX
	
DONE_FIX1
	LDR R0, =ONE
	BL ST7735_OutString
	MOV R0, R11
	BL ST7735_OutChar
	B DONE_FIX

DONE_FIX2
	LDR R0, =TWO
	BL ST7735_OutString
	MOV R0, R11
	BL ST7735_OutChar
	MOV R0, R10
	BL ST7735_OutChar
	B DONE_FIX

DONE_FIX3
	LDR R0, =THREE
	BL ST7735_OutString
	MOV R0, R11
	BL ST7735_OutChar
	MOV R0, R10
	BL ST7735_OutChar
	MOV R0, R9
	BL ST7735_OutChar
	B DONE_FIX
DONE_FIX4
	MOV R0, R11
	BL ST7735_OutChar
	MOV R0, #46
	BL ST7735_OutChar
	MOV R0, R10
	BL ST7735_OutChar
	MOV R0, R9
	BL ST7735_OutChar
	MOV R0, R8
	BL ST7735_OutChar
	B DONE_FIX

	
DONE_FIX	
	POP {R4-R7}
	POP {R4-R12, LR}
	BX LR

     ALIGN
;* * * * * * * * End of LCD_OutFix * * * * * * * *

     ALIGN                           ; make sure the end of this section is aligned
     END                             ; end of file