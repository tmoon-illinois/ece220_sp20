.ORIG   x3000
            LD      R0,A        ;data to display 
POLL    
            LDI     R1, DSRPtr  ;load DSR to register
            BRzp    POLL        ;repeat if ready bit is 0
            STI     R0, DDRPtr  ;store data to DDR 
            HALT
DSRAddr     .FILL   xFE04
DDRAddr     .FILL   xFE06
A           .FILL   x0041
.END
