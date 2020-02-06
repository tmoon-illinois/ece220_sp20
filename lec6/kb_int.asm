.ORIG   x3000
;load ISR address to INTV (M[x0180] <- MyISR)
    LEA     R0, MyISR
    STI     R0, KBINTV 
;enable IE bit of KBSR
    LD      R3, EN_IE
    STI     R3, KBSR 

AGAIN   
    LD  R0,NUM2 ;infinite loop printing '2'
    OUT     
    BRnzp   AGAIN

MyISR
    ST  R0,SaveR0 ;callee-save
    ST  R7,SaveR7 ;callee-save
    LDI R0,KBDR ;read a charcter from keyboard and clear ready bit
    HALT    
    LD  R0,SaveR0
    LD  R7,SaveR7 
    RTI
EN_IE   .FILL   x4000 ;enable IE 0100_0000_0000_0000
NUM2    .FILL   x0032 ;'2'
KBSR    .FILL   xFE00
KBDR    .FILL   xFE02
KBINTV  .FILL   x0180 ;INT vector table address for keyboard
SaveR0  .BLKW   #1
SaveR7  .BLKW   #1
.END
