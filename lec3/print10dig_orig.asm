	.ORIG	x3000
	LEA	R3,Binary
	LD	R6,ASCII
	LD	R7,COUNT
AGAIN	
	TRAP	x23
	ADD	R0,R0,R6
	STR	R0,R3,#0
	ADD	R3,R3,#1
	ADD	R7,R7,#-1
	BRp	AGAIN
        HALT
ASCII	.FILL	xFFD0
COUNT	.FILL	#3
Binary	.BLKW	#3
	.END
