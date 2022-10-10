#include "gpio.h"

/********************************************************************************
* main: Initierar minkrodatrons i/o portar. 
		Tänder alla dioder vid tryckknapp 1 & 2 trycks ner. 
		Tänder och släcker dioder i storleksordning enligt pinnumret.
		Tänder och släcker dioder i fallande ordning enligt pinnumret. 
		Släcker alla dioder när ingen knapp trycks ner. 
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

