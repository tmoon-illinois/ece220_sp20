;negate the value in R0
        .ORIG	x3000
	LD	R0,Value    ;load a value into R0
	JSR	NEG         ;jump to subroutine NEG
	ADD	R1,R6,R0    ;verify the result
	HALT
;subroutine NEG: R6 = -R0
NEG	ST	R0,SaveR0   ;callee-save register
	NOT	R0,R0
	ADD	R6,R0,#1
	LD	R0,SaveR0   ;recover register
	RET
Value	.FILL	#5
SaveR0	.BLKW	#1
	.END
