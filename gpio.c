#include "gpio.h" // Inkluderingsdirektiv

/********************************************************************************
* setup: Initierar mikrodatorns i/o portar. Lysdiodernas pinnar 6-8 sätts till
         utportar. Sätter tryckknapparnas pin till att vara antingen "hög eller 
		 låg".
********************************************************************************/
void setup(void)
{
	DDRD = ((1 << LED_G) | (1 << LED_R));
	DDRB = (1 << LED_B);
	PORTB = (1 << BUTTON_1) | (1 << BUTTON_2);
	
	return;
}

/********************************************************************************
* delay_ms: Skapar angiven fördröjning i millsekunder.
*
*           - delay_time_ms: Fördröjningstid i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; ++i)
	{
		_delay_ms(1);
	}

	return;
}

/********************************************************************************
* leds_on: Tänder alla lysdioder.
********************************************************************************/
void leds_on(void)
{
	LED_B_ON;
	LED_G_ON;
	LED_R_ON;
	
	return;
}

/********************************************************************************
* leds_off: Släcker alla lysdioder.
********************************************************************************/
void leds_off(void)
{
	LED_B_OFF;
	LED_G_OFF;
	LED_R_OFF;
	
	return;
}

/********************************************************************************
* leds_blink_forward: Blinkar lysdioder anslutna till 6, 7, 8 i ordning 6, 7, 8.
*                     delay_ms: Blinkhastighet i millisekunder.
********************************************************************************/
void leds_blink_forward(const uint16_t blink_speed_ms)
{
	LED_B_ON;
    LED_G_OFF;
	LED_R_OFF;
	delay_ms(blink_speed_ms);
	
	LED_B_OFF;
	LED_G_ON;
	LED_R_OFF;
	delay_ms(blink_speed_ms);
	
	LED_B_OFF;
	LED_G_OFF;
	LED_R_ON;
    delay_ms(blink_speed_ms);
	
	return;
}

/********************************************************************************
* leds_blink_reverse: Blinkar lysdioder anslutna till 8, 7, 6 i ordning 8, 7, 6.
*                     delay_ms: Blinkhastighet i millisekunder. 
********************************************************************************/
void leds_blink_reverse(const uint16_t blink_speed_ms)
{
	LED_B_OFF;
	LED_G_OFF;
	LED_R_ON;
	delay_ms(blink_speed_ms);
		
	LED_B_OFF;
	LED_G_ON;
	LED_R_OFF;
	delay_ms(blink_speed_ms);
		
	LED_B_ON;
	LED_G_OFF;
	LED_R_OFF;
	delay_ms(blink_speed_ms);
		
	return;
}