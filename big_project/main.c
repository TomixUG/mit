/*
 * test.cpp
 *
 * Created: 27.01.2023 10:10:11
 * Author : Student
 */ 

#include <avr/io.h>
#define F_CPU 16000000
#include <util/delay.h>

unsigned char choose[6] = {0b01111111, 0b10111111, 0b11011111, 0b11101111, 0b11110111, 0b11111011};
unsigned char segmenty[16]={0xc0,0xf9,0xA4,0xb0,0x99,0x92,0x82,0xd8,0x80,0x90,0x88,0x83,0xc6,0xA1,0x86,0x8e};
	
unsigned char input[6] = {255, 255, 255, 255, 255, 255};

unsigned char klav()
{
	unsigned char vystup[16] = {1,2,3,10,4,5,6,11,7,8,9,12,14,0,15,13};
	int pokusy = 0;
	for(int radek = 3; radek >=0; radek--)
	{
		PORTE =~ (1<<radek);
		_delay_ms(1);
		for(int sloupec = 4; sloupec <= 7; sloupec++)
		{
			if((PINE&(1<<sloupec))==0)
			{
				return (vystup[pokusy]);
			}
			pokusy++;
		}
		
	}
	
	return 255; // 0xff
	
}

int main(void)
{
    /* Replace with your application code */
	
	DDRF = 0xFF; // leds
	DDRK = 0x00; // buttons
	
	DDRE=0x0f; // keyboard
	
	DDRB=0xff; // 7 seg data
	DDRD=0xff;  // 7 seg active
	
	PORTF=0xff;
	
    while (1) 
    {
		// start entering data after pressing 7th button
		if((PINK&(1<<7))==0)
		{
			// turn on all leds for 1 second before starting the entering proccess
			PORTF=0b00000000; 
			_delay_ms(1000);
			
			// entering data
			for(int i = 5; i > 0; i--)
			{
				PORTF=0b01111111; // turn on first led
				_delay_ms(2000);
				
				// get the data from keyboard	
				input[i] = klav();
							
				PORTF=0b11111111; // turn off first led
				_delay_ms(500);
			}
		}
		
		// show the data
		for(int i = 0; i < 6; i++)
		{
			PORTD = choose[i]; // choose the display
			
			// nothing
			if(input[i] == 255)
			{
				PORTB = 0b10111111;
			} else 
			{
				PORTB = segmenty[input[i]];
			}
			
			_delay_ms(1);
		}

    }
}

