/*
 * Source of code that LED toggle/switch with simplificated function
 *
 * Created: 1/25/2023 01:39:33
 * Author : Misha Zaslavskis
 */
#include "led.h"
/*
* A function that LEDS initialization
* This function is setup LED pin mode each register during initialization
* Return value: None
* Argument: None
*/
void led_init()
{
	DDRD |= (1 << DDD2); // Set OUTPUT mode in PD2 pin
	DDRD |= (1 << DDD3); // Set OUTPUT mode in PD3 pin
	DDRD |= (1 << DDD4); // Set OUTPUT mode in PD4 pin
}
/*
* You can change color and state of LEDs any time by using defined value (e.g. HIGH, LOW, RED_LED, GREEN_LED, BLUE_LED).
* You can look defined value with macros #define in led.h. 
* State of led: HIGH is means that led turn on and LOW is means that led turn off
* RED_LED, GREEN_LED, BLUE_LED is pin of leds. Look in led.h file
* Argument: color_led (uint8_t) - choose pin of led. stat (uint8_t) - set state led. 
* Return value: None
*/
void set_led(uint8_t color_led, uint8_t stat)
{
	if (stat) PORTD |= (1 << color_led); // Set HIGH level selected color led 
	else PORTD &= ~(1 << color_led); // Set LOW level selected color led
}
/*
* Change state for all LEDs function. 
* You can change state of LEDs by defined HIGH and LOW
* State of led: HIGH is means that led turn on and LOW is means that led turn off
* Argument: stat (uint8_t) - set state led.
* Return value: None
*/
void all_leds(uint8_t stat)
{
	if (stat)
	{
		PORTD |= (1 << RED_LED);
		PORTD |= (1 << GREEN_LED);
		PORTD |= (1 << BLUE_LED);
	}
	else
	{
		PORTD &= ~(1 << RED_LED);
		PORTD &= ~(1 << GREEN_LED); 
		PORTD &= ~(1 << BLUE_LED); 
	}
}