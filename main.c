
//*** Program Header ***
/************************************************************************************
	File Name: External_InterruptsATMega16		
	Author:	   ASHISH SHARMA	
	Date:	   March 21, 2022 
	Modified:  None	
	Description:    This program will:
			1) Programmed the external interrupt peripheral of the microcontroller ATMEGA16
************************************************************************************/

// Preprocessor ===================================================================
#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>

int main(void)
{
	DDRB |= (1<<DDB0) | (1<<DDB1);	//Data register set as Output.
	sei();	//GIE Set
	GICR |= (1<<INT1) | (1<<INT0);	//Enable Interrupts
	MCUCR |= (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);	
		
    while (1) 
    {

    }
}

/*** Interrupt Service Routine (the ISR) functions will be executed respectively when INT0 and INT1 interrupts will called **/

ISR(INT0_vect)
{
	PORTB |= (1<<PB0);		
}

ISR(INT1_vect)
{
	PORTB &= (~(1<<PB0));
}
