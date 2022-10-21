/*
 * blik.c
 *
 * Created: 21.10.2022 10:31:52
 * Author : Student
 * program blikajici led na 0. bitu portu F f=1Hz
 */ 

#include <avr/io.h>
#define F_CPU 16000000 
#include <util/delay.h>


int main(void)
{
	// DDR
	DDRF = 0xFF; // set all registers to OUTPUT
	
    while (1) 
    {
		PORTF = 0b01111110; // turn on first and last LED
		_delay_ms(100); 
		PORTF = 0xff; // turn off all LEDs
		_delay_ms(100);
    }
}

