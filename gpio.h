#ifndef GPIO_H_
#define GPIO_H_

#define F_CPU 16000000UL // 16MHz klockfrekvens
#include <avr/io.h> // Inkluderingsdirektiv
#include <util/delay.h> // Inkluderingsdirektiv

#define LED_R 6 //Lysdiod 1 ansluten till pin 6
#define LED_G 7 //Lysdiod 2 ansluten till pin 7
#define LED_B 0 //Lysdiod 3 ansluten till pin 8
#define BUTTON_1 4 //Tryckknapp 1 ansluten till pin 12
#define BUTTON_2 5 //Tryckknapp 1 ansluten till pin 13

#define LED_R_ON PORTD |= (1 << LED_R) //Tänder lysdiod 1
#define LED_G_ON PORTD |= (1 << LED_G) //Tänder lysdiod 2
#define LED_B_ON PORTB |= (1 << LED_B) //Tänder lysdiod 3

#define LED_R_OFF PORTD &= ~(1 << LED_R) //Släcker lysdiod 1
#define LED_G_OFF PORTD &= ~(1 << LED_G) //Släcker lysdiod 2
#define LED_B_OFF PORTB &= ~(1 << LED_B) //Släcker lysdiod 3

#define BUTTON_1_IS_PRESSED ((PINB & (1 << BUTTON_1)) != 0) //Kontrollerar om tryckknapp 1 är nedtryckt
#define BUTTON_2_IS_PRESSED ((PINB & (1 << BUTTON_2)) != 0) //Kontrollerar om tryckknapp 2 är nedtryckt

/********************************************************************************
* setup: Initierar mikrodatorns i/o portar. 
********************************************************************************/
void setup(void);

/********************************************************************************
* delay_ms: Skapar angiven fördröjning i millsekunder.
*
*           - delay_time_ms: Fördröjningstid i millisekunder.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms);

/********************************************************************************
* leds_on: Tännder alla lysdioder.
********************************************************************************/
void leds_on(void);

/********************************************************************************
* leds_off: Släcker alla lysdioder. 
********************************************************************************/
void leds_off(void);

/********************************************************************************
* leds_blink_forward: Blinkar lysdioder anslutna till 6, 7, 8 i ordning 6, 7, 8.
********************************************************************************/
void leds_blink_forward(const uint16_t blink_speed_ms);

/********************************************************************************
*  leds_blink_reverse: Blinkar lysdioder anslutna till 6, 7, 8 i ordning 8, 7, 6.
********************************************************************************/
void leds_blink_reverse(const uint16_t blink_speed_ms); 



#endif