;Subtraction: R1 = R2 - R3
        .ORIG	x3000
	LD	R2,Value1   ;load a value into R2
	LD	R3,Value2   ;load a value into R3
	JSR	SUBTR       ;jump to subroutine
	HALT
;NEG: R6 = -R0
NEG	ST	R0,SaveR0_NEG
	NOT	R0,R0
	ADD	R6,R0,#1
	LD	R0,SaveR0_NEG
	RET
;SUBTR: R1 = R2 - R3
SUBTR   ST      R0, SaveR0_SUB
        ST      R6, SaveR6_SUB
        ;ST      R7, SaveR7_SUB
        ADD     R0, R3, #0
        JSR     NEG
        ADD     R1, R2, R6
        LD      R0, SaveR0_SUB
        LD      R6, SaveR6_SUB
        ;LD      R7, SaveR7_SUB
        RET
Value1	.FILL	#5
Value2	.FILL	#4
SaveR0_NEG	.BLKW	#1
SaveR0_SUB      .BLKW	#1
SaveR6_SUB      .BLKW	#1
SaveR7_SUB      .BLKW	#1
	.END
