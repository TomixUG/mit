/*
 * GccApplication1.cpp
 *
 * Created: 02.12.2022 10:30:06
 * Author : Student
  */

	// Na 7 seg uplne vprao zobrazujte cislo 0 az F, meni se kazdou 0.5s.
	 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

unsigned char segmenty[16]={0xC0, 0xF9, 0xA4, 0xB0, 0x99, 0x92, 0x82, 0xF8, 0x80, 0x90, 0x88, 0x83, 0xC6, 0xA1, 0x86, 0x8E};

int main(void)
{
    /* Replace with your application code */
    

int main(void)
{
    /* Replace with your application code */
    
	DDRB=0xff;
	DDRD=0xff;
	
	PORTD=0xDF;
	
	while (1) 
    {
		for(int i = 0; i<16;i++)
		{
			PORTB = segmenty[i];
			_delay_ms(500);
		}
	}
}

