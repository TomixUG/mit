/*
 * GccApplication1.cpp
 *
 * Created: 13.01.2023 10:27:55
 * Author : Student
 */ 

#include <avr/io.h>
#include <util/delay.h>

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
	// pull up resistors are enabled on line 16
	
	DDRE=0x0f;
	DDRF=0xff;
	unsigned char cislo;
	
    while (1) 
    {
		cislo = klav();
		
		PORTF = ~cislo; // zobrazit promennou na LEDkach
		_delay_ms(100);
    }
}

