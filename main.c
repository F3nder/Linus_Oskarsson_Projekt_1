#include "gpio.h"

/********************************************************************************
* main: Initierar minkrodatrons i/o portar. 
		T�nder alla dioder vid tryckknapp 1 & 2 trycks ner. 
		T�nder och sl�cker dioder i storleksordning enligt pinnumret.
		T�nder och sl�cker dioder i fallande ordning enligt pinnumret. 
		Sl�cker alla dioder n�r ingen knapp trycks ner. 
********************************************************************************/
int main(void)
{
	setup();
	
    while (1) 
    {
		if (BUTTON_1_IS_PRESSED && BUTTON_2_IS_PRESSED)
		{
			leds_on();
		}
		if (BUTTON_1_IS_PRESSED && !BUTTON_2_IS_PRESSED)
		{
			leds_blink_forward(100);
		}
		if (BUTTON_2_IS_PRESSED && !BUTTON_1_IS_PRESSED)
		{
			leds_blink_reverse(100);
		}
		else
		{
			leds_off();
		}
    }
	return 0;
}

