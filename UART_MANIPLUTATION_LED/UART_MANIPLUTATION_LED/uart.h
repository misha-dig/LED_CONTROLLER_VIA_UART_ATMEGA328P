/*
 * Header code of UART library for atmega328p MCU.
 *
 * Created: 1/25/2023 01:39:33
 * Author : Misha Zaslavskis
 */
#ifndef __UART_H
#define __UART_H
void UART_init();
void UART_Transmit_single_character(unsigned char data);
void UART_Transmit_multiple_characters(unsigned char* data);
unsigned char UART_Receive_single_character();
void clear_buffer(unsigned char* data, int amount_characters);
#endif // __UART_H

