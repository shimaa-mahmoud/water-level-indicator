#include "avr/io.h"
#include "lcd.h"
#include "util/delay.h"

int main (void)
{
	LCD_init();
	DDRD &= ~0xF0; // switches
	PORTD |= 0xF0;  // pull up resistors

	DDRB &= ~ (1 << PB7);
	PORTB |= ( 1<< PB7);

	DDRC |= 0X03; // motor
	PORTC &= ~ 0X03;  // initially off
	uint8 filling ;
	while (1)
	{
		if (!(PINB & (1 << PB7) ))
		{
			filling = 1;
		}
		else
		{
			filling = 0;
		}

		if (!(PIND & (1 << PD4)))
		{
			LCD_goToRowColumn(0,5);
			LCD_displayString("100% full  ");
			PORTC &= ~ 0X03;
		}
		else if (!(PIND & (1 << PD5) ))
		{
			LCD_goToRowColumn(0,5);
			LCD_displayString("50% full   ");

		}
		else if (!(PIND & (1 << PD6) ))
		{
			LCD_goToRowColumn(0,5);
			LCD_displayString("25% full   ");
		}
		else if (!(PIND & (1 << PD7) ))
		{
			LCD_goToRowColumn(0,5);
			LCD_displayString(" 5% full   ");
			if ( filling )
				PORTC |= 0X01;
			else
				PORTC &= ~ 0X03;
		}

	}//end while
}//end main
