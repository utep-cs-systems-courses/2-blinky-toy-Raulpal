	.arch msp430g2553
	.p2align 1,0
	.text

	.equ GREEN, 1		;Green led BIT0
	.equ RED, 64 		;red led BIT6

	.global greenControl
	.global redControl

	.extern P1OUT

greenControl:			; green led
	cmp #0,r12
	 jz greenOff
	bis #GREEN, &P1OUT
	pop r0
	
greenOff: and #~GREEN,&P1OUT
	  pop r0

	
redControl:			; red led 
	cmp #0,r12
	 jz redOff
	bis #RED, &P1OUT
	pop r0
	
redOff: and #~RED,&P1OUT
	pop r0
