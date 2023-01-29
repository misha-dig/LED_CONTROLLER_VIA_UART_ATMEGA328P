/*
 * Header code of LED toggling/switching with simplificated function
 *
 * Created: 1/25/2023 01:39:33
 * Author : Misha Zaslavskis
 */
#ifndef __LED_H
#define __LED_H

#include <avr/io.h>
#include <stdint.h>

#define RED_LED PORTD2
#define GREEN_LED PORTD3
#define BLUE_LED PORTD4
#define HIGH 1
#define LOW 0

void set_led(uint8_t color_led, uint8_t stat);
void all_leds(uint8_t stat);
void led_init();

#endif // __LED_H