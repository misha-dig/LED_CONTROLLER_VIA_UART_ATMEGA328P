/*
 * UART command code for led switching 
 *
 * Created: 1/25/2023 01:39:33
 * Author : Misha Zaslavskis
 */
 
/*  Set frequency crystal oscillator of MCU for working delay function properly (NOTE: NOT CHANGE CLOCK OF MCU) */
#define F_CPU 14745600U
/* Libraries */
#include <avr/io.h> // A core AVR library
#include <util/delay.h> // AVR library for polling delay function
#include <stdint.h> // A standard GCC library for declaration integer variable with various bits size (e.g use uint8_t and uint16_t) 
/* Our library */
#include "led.h"
/* Set maximum size characters which we can send command in Serial port UART to perform action (e.g. Switching leds) */
#define BUFFER_SIZE 16

/* Main function */
int main(void)
{
	/* Initialization peripherals */
	led_init(); // led initialization 
	UART_init(); // UART initialization 
	UART_Transmit_multiple_characters("Welcome! \r\n"); // Display word "Welcome" in console for checking UART is working. 
	
	/* Test LEDS */
	all_leds(HIGH);
	_delay_ms(50);
	all_leds(LOW);
	
	/* Infinite loop */
    while (1) 
    {
		/* Declaration buffer */
		uint8_t buffer[BUFFER_SIZE] = {'\0'}; // Buffer array for entering command
		
		/* Loop that find ASCII character to perform commands when hit a ENTER button */
		for (int count_buf = 0; count_buf < BUFFER_SIZE - 1; count_buf++)
		{
			do
			{
				/* Receive single characters after send character in UART console */
				buffer[count_buf] = UART_Receive_single_character();
			}
			/* Checking that no special ASCII characters. If special character is found you need to reenter letter, digits, space, carriage return */
			while ((buffer[count_buf] < 32 && buffer[count_buf] > 13) || buffer[count_buf] < 13);
			
			/* Exit receiving characters after hitting enter button in keyboard or putting carriage return in your serial port terminal */
			/* Check character has CR. If found CR character finish send UART and exit from this for loop for starting perform tasks */
			if (buffer[count_buf] == 13)
			{
				UART_Transmit_multiple_characters(buffer); // Print the buffer in UART terminal for checking purpose
				break; //Exit from this loop operation
			}
		}
		
		/* Execute command if you entered correct name of command in serial terminal */
		/* You must put a argument strlen(buffer) - 1 in each function strncmp to avoid doesn't working this commands */
		if (strncmp(buffer, (uint8_t*)"RED_LED_ON", strlen(buffer) - 1) == 0) set_led(RED_LED, HIGH); // Turns on red led
		else if (strncmp(buffer, (uint8_t*)"RED_LED_OFF", strlen(buffer) - 1) == 0) set_led(RED_LED, LOW); // Turn off red led 
		
		else if (strncmp(buffer, (uint8_t*)"GREEN_LED_ON", strlen(buffer) - 1) == 0) set_led(GREEN_LED, HIGH); // Turns on green led
		else if (strncmp(buffer, (uint8_t*)"GREEN_LED_OFF", strlen(buffer) - 1) == 0) set_led(GREEN_LED, LOW); // Turn off green led
		
		else if (strncmp(buffer, (uint8_t*)"BLUE_LED_ON", strlen(buffer) - 1) == 0) set_led(BLUE_LED, HIGH); // Turns on blue led
		else if (strncmp(buffer, (uint8_t*)"BLUE_LED_OFF", strlen(buffer) - 1) == 0) set_led(BLUE_LED, LOW); // Turn off blue led
		
		else if (strncmp(buffer, (uint8_t*)"ALL_LEDS_ON", strlen(buffer) - 1) == 0) all_leds(HIGH); // Turns on all LEDs
		else if (strncmp(buffer, (uint8_t*)"ALL_LEDS_OFF", strlen(buffer) - 1) == 0) all_leds(LOW); // Turn off all LEDs
		
		/* Message that incorrect entering command when enter another command than above code line*/
		else UART_Transmit_multiple_characters("Error! Unable recognize a command in this code. Please try other commands... \r\n"); 
    }
}