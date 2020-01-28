        .ORIG   x3000
        LD      R1, VAL1
        LD      R2, VAL2
        LD      R3, VAL3
        LEA     R4, ADD3
        JSRR    R4 
        HALT
; ADD3 subroutine: R0 = R1 + R2 + R3
ADD3    
        AND     R0, R0, #0
        ADD     R0, R0, R1
        ADD     R0, R0, R2
        ADD     R0, R0, R3
        RET
VAL1    .FILL   #2
VAL2    .FILL   #3
VAL3    .FILL   #4
        .END

