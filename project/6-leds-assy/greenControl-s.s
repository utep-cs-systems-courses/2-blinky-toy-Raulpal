	.arch msp430g2553
	.p2align 1,0
	.text

	.equ GREEN, 1  		; grend led BIT0

	.global greenControl
	.extern P1OUT

greenControl:
	cmp #0, r12
	jz off
	bis #GREEN, &P1OUT		;or
	pop r0
off:	and #~GREEN, &P1OUT
	pop r0
