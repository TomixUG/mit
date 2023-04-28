		.org 0
		ldi r16, 0xff ; temporarne si do registru r16 dame 0xff
		out DDRF, r16 ; registr r16 dame to DDRF
	
		out PORTF, r16 ; vypneme vsechny LEDky

znovu:	cbi PORTF, 0 ; nastavit nulu na nutly bit portu F
		sbi PORTF, 7
		rcall zpozdi
		sbi PORTF, 0 ; nastavit na jedna nulty bit portu F
		cbi PORTF, 7
		rcall zpozdi
		rjmp znovu
		
zpozdi: ldi r17, 42

skok3:	ldi r18,250 ; nastavime 250
skok2:	ldi r19, 250 ; nastavime 250
skok1:	dec r19 ; decrement register, 1 strojovy cyklus
		brne skok1
		dec r18
		brne skok2
		dec r17
		brne skok3
		ret