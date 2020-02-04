;
	.ORIG	x3000
        LD      R1, VALUE_R1
        LD      R2, VALUE_R2
	;caller-save
	ST	R2,SaveR2_MAIN	
	;perform negate
	JSR	NEG
	;restore reg
	LD	R2,SaveR2_MAIN
	HALT
SaveR2_MAIN	.BLKW	#1
VALUE_R1        .FILL   #1
VALUE_R2        .FILL   #2
;NEG: R2 = -R1
;IN: R1
;OUT: R2
NEG	
;callee-save
	ST	R1,SaveR1_NEG
;perform negate
	NOT	R1,R1
	ADD	R2,R1,#1
;restore regs
	LD	R1,SaveR1_NEG
	RET
SaveR1_NEG	.BLKW	#1

;PUSH subroutine
;IN: R0 (value)
;OUT: R5(0-success, 1-fail)
;R3: STACK_END
;R6: STACK_TOP
PUSH
;callee-save & initialize registers
	ST	R3,PUSH_SaveR3	
	ST	R6,PUSH_SaveR6
	AND	R5,R5,#0	
	LD	R3,STACK_END
	LD	R6,STACK_TOP
;overflow?
;Check if STACK_TOP = STACK_END - 1
;Or check if STACK_TOP - (STACK_END - 1) = 0
	ADD	R3,R3,#-1
	NOT	R3,R3
	ADD	R3,R3,#1
	ADD	R3,R3,R6
	BRz	OVERFLOW ;stack is full
;it it NOT overflow
	STR	R0,R6,#0
	ADD	R6,R6,#-1
	ST	R6,STACK_TOP
	BRnzp	DONE_PUSH

;it is overflow
OVERFLOW
	ADD	R5,R5,#1

;restore registers
DONE_PUSH
	LD	R3,PUSH_SaveR3
	LD	R6,PUSH_SaveR6
	RET

;POP subroutine
;IN: none
;OUT: R0 (value)
;OUT: R5 (0: success, 1: fail)
;R3: STACK_START
;R6: STACK_TOP
POP
;callee-save & initialize registers
	ST	R3,POP_SaveR3
	ST	R6,POP_SaveR6
	AND	R5,R5,#0	
	LD	R3,STACK_START
	LD	R6,STACK_TOP
;underflow?
;Check if STACK_TOP = STACK_START
;Or check if STACK_TOP - STACK_START = 0
	NOT	R3,R3
	ADD	R3,R3,#1
	ADD	R3,R3,R6
	BRz	UNDERFLOW ;stack is empty
;it it NOT underflow
	ADD	R6,R6,#1
	LDR	R0,R6,#0
	ST	R6,STACK_TOP
	BRnzp	DONE_POP

;it is underflow
UNDERFLOW
	ADD	R5,R5,#1

;restore registers
DONE_POP
	LD	R3,POP_SaveR3
	LD	R6,POP_SaveR6
	RET


PUSH_SaveR3	.BLKW	#1
PUSH_SaveR6	.BLKW	#1
POP_SaveR3	.BLKW	#1
POP_SaveR6	.BLKW	#1

STACK_START	.FILL	x4000
STACK_END	.FILL	x3FF0
STACK_TOP	.FILL	x4000
	.END
