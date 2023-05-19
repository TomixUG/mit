		.org 0
		rjmp HL_PR
		.org OC1Aaddr
		rjmp PPOP
HL_PR:	
		LDI r16, 0xff
		OUT DDRB, r16 // 7seg
		OUT DDRD, r16 // 7seg
		
		LDI r17, 0xDF
		out PORTD, r17

		ldi r18, HIGH(16000) // vezme hornich 8 bitu z cisla 16000
		sts OCR1AH, r18 // uloz registr r18 do pameti OCR1AH
		
		ldi r18, LOW(16000)
		sts OCR1AL, r18

		ldi r18, 0x0d
		sts TCCR1B, r18

		ldi r18, 0x02
		sts TIMSK1, r18 
		
		sei // globali poruseni

		ldi zh, HIGH(TAB*2) // naplneni do registroveho paru z
		ldi zl, LOW(TAB*2)                
		ldi r20, 16
konec:	rjmp konec

PPOP:	LPM r21, z+
		out PORTB, r21
		dec r20
		brne end
		ldi r20, 16
		LDI zh, high(tab*2)
		LDI zl, low(tab*2)

end:	reti

		// pamet ma usporadani 128k x 16b
		// takze 16b na jeden zaznam, protoze ukladame 8 bitove cisla, muzeme na jedno misto ulozit 2
TAB:	.db 0xc0, 0xf9
		.db 0xa4, 0xb0
		.db 0x99, 0x92
		.db 0x82, 0xd8
		.db 0x80, 0x90
		.db 0x88, 0x83
		.db 0xc6, 0xa1
		.db 0x86, 0x8e
