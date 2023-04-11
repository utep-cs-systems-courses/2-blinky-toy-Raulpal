	.arch msp430g2553
	.p2align 1,0
	.text

	.equ GREEN, 1
	.equ RED, 64

	.global led_init
	.global greenControl
	.global redControl

	.extern P1OUT
	.extern P1DIR
	
	
led_init:			; Set up leds
        mov #GREEN, r12
	bis #RED, r12
	bis r12, &P1DIR
	and #~GREEN, &P1OUT
	and #~RED, &P1OUT
	pop r0

greenControl:			; Green led BIT0
	xor #GREEN, &P1OUT
	pop r0
	
redControl:			; Red led BIT6
	xor #RED,&P1OUT
	pop r0
