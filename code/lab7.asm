
	.ORIG	x3000

	AND	R1, R1, #0		; initialize all registers 
	AND	R2, R2, #0
	AND	R3, R3, #0
	AND	R4, R4, #0
	AND	R5, R5, #0
	AND	R6, R6, #0
	AND	R7, R7, #0


	LEA R0, greetMess		; loads inputMessage into R0
	TRAP x22			; TRAP x22 prints out R0


	LEA R0, promptMess
	TRAP x22
	
GETCLOOP	GETC
	OUT
	LD	R3, LF			; loads lineFeed into R3
	ADD	R3, R0, R3
	BRZ	CHECKFLAG


	LD 	R3, neg			; load -45 into R3
	ADD	R2, R0,	R3		; add R3 to R0/ -45 + RO IS NOW STORED IN R2
	BRZ	ifNeg			; if the getC input is neg branches to ifNeg else continues 

	; if input is not negative 

	LD	R4, numFortyEight       	; loads -48 into R4
	ADD	R1, R0, R4			; adds R0/getC value + (-48) and stores in R1
	ST 	R1, digit			; stores R1 (getC value + (-48)) in value/memory

	;int = int x 10 + value

	AND	R4, R4, #0			; initialize R4
	AND	R3, R3, #0			; initialize R3
	AND	R1, R1, #0			; initialize R1
	LD	R3, INT				; load int into R3
	ADD	R4, R4, #10			; set R4 equal to 10
xTenLoop					; enter xTenLoop
	ADD 	R1, R1, R3			; add R3 (int) to R1
	ADD	R4, R4, #-1			; decrement R4--
	BRP	xTenLoop			; enter xTenLoop
	LD	R4, digit			; load digit into R4
	ADD 	R1, R1, R4			; add R4 into R1
	BR	GETCLOOP			; after loop hits neg branch to getCloop
	
flagIsNeg
	AND	R1, R1, 0
	AND 	R2, R2, 0
	AND 	R3, R3, 0
	AND 	R4, R4, 0
	LD	R6, digit
	ADD	R2, R2, R6
	LD	R4, sixteen
	LEA 	R3, maskArray

arrayLoop
	AND	R1, R2, R3
	BRZ	valueIsZero
	LD	R0, one
	OUT
	ADD	R3, R3, #1
	ADD	R4, R4, #-1
	BRP arrayLoop 
	
valueIsZero
	LD	R0, fortyEight		; load ascii 48 (#0) into R0
	OUT				; print out R0
	ADD	R4, R4, #-1
	ADD	R3, R3, #1
	BRP	arrayLoop


CHECKFLAG
	AND	R7, R7, 0
	ADD 	R7, R7, #-1			; store -1 to R7
	LD  	R3, flag			; load flag value into R3
	ADD 	R3, R7, R3			; add R3 and R7
	BRZ	flagIsNeg 			; if R3 + R7 == 0 branch / flag == 1
; need to branch back to getCloop


ifNeg							
	AND 	R3, R3, 0				; if getC value is negative
	ADD	R3, R3, #1				; add 1 to R3
	LD	R4, flag				; load flag value into R4
	ADD	R3, R4, R3				; add flag value to 1 store in R3
	ST	R3, flag				; increments flag to 1
	

	TRAP	x25					; this HALTS the program

greetMess .STRINGZ "Welcome to the conversion program \n"			; declare greeting message
promptMess .STRINGZ "Enter a decimal number or X to quit: \n"			; declares message prompting user input

LF	.FILL	-10
neg	.FILL	-45
flag	.FILL	0
numFortyEight	.FILL	-48
getCVal	.FILL	0
INT 	.FILL	0
value	.FILL	0
digit	.FILL	0
sixteen	.FILL	16
fortyEight	.FILL	48
one	.FILL 49
maskArray 		.FILL x8000
			.FILL x4000
			.FILL x2000
			.FILL X1000
			.FILL x0800
			.FILL x0400
			.FILL x0200
			.FILL x0100
	  		.FILL x0080
			.FILL x0040
			.FILL x0020
			.FILL x0010
			.FILL x0008
			.FILL x0004
			.FILL x0002
			.FILL x0001

	.END