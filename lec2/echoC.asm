.ORIG	    x3000
POLL1	
            LDI	    R1, KBSRAddr
	    BRzp    POLL1	
	    LDI	    R0, KBDRAddr
POLL2	
            LDI	    R1, DSRAddr
	    BRzp    POLL2
	    STI	    R0, DDRAddr
            HALT
KBSRAddr    .FILL   xFE00
KBDRAddr    .FILL   xFE02
DSRAddr     .FILL   xFE04
DDRAddr     .FILL   xFE06
.END
