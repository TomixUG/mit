/*
 * GccApplication2.cpp
 *
 * Created: 24.02.2023 10:30:50
 * Author : Student
 */

#include <avr/io.h>
#include <avr/interrupt.h>
volatile unsigned char video[6];
volatile int i = 0;
volatile int active = 0xfe;
ISR(TIMER0_COMPA_vect)
{
    unsigned char segmenty[16] = {0xc0, 0xf9, 0xA4, 0xb0, 0x99, 0x92, 0x82, 0xd8, 0x80, 0x90, 0x88, 0x83, 0xc6, 0xA1, 0x86, 0x8e};
    PORTB = segmenty[video[i]];
    PORTD = ~(1 << i);
    i++;

    if (i == 6)
    {
        i = 0;
    }
}

int main(void)
{
    DDRB = 0xff;
    DDRD = 0xff;

    TCCR0A = 0x02;
    TCCR0B = 0x03;

    OCR0A = 250;
    TIMSK0 |= (1 << OCIE0A);
    sei();

    for (int i = 0; i < 6; i++)
    {
        video[i] = i + 1;
    }

    /* Replace with your application code */
    while (1)
    {
    }
}
