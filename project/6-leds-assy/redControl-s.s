	.arch msp430g2553
	.p2align 1,0
	.text

	.equ RED, 64   		; red led BIT6

	.global redControl
	.extern P1OUT

redControl:
	cmp #0, r12
	jz off
	bis #RED, &P1OUT
	pop r0
off:	and #~RED, &P1OUT
	pop r0
