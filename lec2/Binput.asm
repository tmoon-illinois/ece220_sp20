.ORIG       x3000
POLL        
            LDI     R5, KBSRAddr    ;load KBSR to register 
            BRzp    POLL            ;repeat if ready bit is 0
            LDI     R2, KBDRAddr    ;load KBDR to register
            HALT
KBSRAddr    .FILL   xFE00
KBDRAddr    .FILL   xFE02
.END
