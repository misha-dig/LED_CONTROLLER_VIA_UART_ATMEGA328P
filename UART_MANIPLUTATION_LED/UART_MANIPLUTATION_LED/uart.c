/*
 * Source of code UART library for atmega328p MCU
 *
 * Created: 1/25/2023 01:39:33
 * Author : Misha Zaslavskis
 */
/* Libraries and headers */
#include <avr/io.h> // A core AVR library
#include <string.h> // A libraries for comparing string function

/* Setting speed transmitting UART interface */
#define BAUD 115200 // Choose speed
#define BAUDRATE ((14745600UL)/(BAUD*16UL)-1) // Calculation baud rate, using formula form data sheet ATmega328p recommendation. 
/*
* A function that UART initialization 
* This function is setup UART during initialization
* Return value: None
* Argument: None
*/
void UART_init()
{
    /* Set baud rate by calculation formula */
    UBRR0H = (unsigned char)(BAUDRATE>>8);
    UBRR0L = (unsigned char)BAUDRATE;
	
	/* Allow UART to transmit and receive buffers */
    UCSR0B = (1<<RXEN0)|(1<<TXEN0);

    /* Set frame format: 8data, 1stop bit */
    UCSR0C = 0b00000110;
}
/*
* A function that UART Transmit single character
* This function can send single bytes data from MCU to targeted device with UART interface
* Return value: None
* Argument: data - is what character you want to transmit FROM MCU to other device. Type variable of data is unsigned char. 
* Example to use:
*       UART_Transmit_single_character('A');
*/
void UART_Transmit_single_character(unsigned char data)
{
    /* Wait for empty transmit buffer */
    while ( !( UCSR0A & (1<<UDRE0)) );
    /* Put data into buffer, sends the data */
    UDR0 = data;
}
/*
* A function that UART Transmit multiple characters
* This function can multi byte send you data from MCU to targeted device with UART interface
* Return value: None
* Argument: data - is what characters you want to transmit FROM MCU to other device. Type variable of data is array of unsigned char.
* Example to use: 
*       unsigned char text[] = "Hello, World! \r\n";
*       UART_Transmit_multiple_characters(text); 
*/
void UART_Transmit_multiple_characters(unsigned char* data)
{
	/* Loop for transmit each characters. How many transmit characters is dependent string length. */
    for(int ch = 0; ch < strlen(data); ch++) UART_Transmit_single_character(data[ch]); // Transmit UART each character 
}
/*
* A function that UART Receive single character from device
* This function can get single byte data from device to MCU. 
* Return value: A data that got from device's sending to MCU via UART interface. Type variable of data is unsigned char. 
* Argument: None
*/
unsigned char UART_Receive_single_character()
{
	/* Wait for data to be received */
	while (!(UCSR0A & (1<<RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}