# LED_CONTROLLER_VIA_UART_ATMEGA328P

A project that led commands via UART in atmega328P popular MCU. In UART section code, we used based repository xanthium-enterprises/atmega328p-10bit-adc-configuration-code (algorithm and register configuration) in some portion of our code. 

Futhermore, you can make own command via sending data from UART interface, so you need to sort myself to understand how work a function. Your code has included comments for explanation how work code. We'll add documenation and examples soon. 

You can change led state via sending command in serial port ternimal and software. Note that you must send carriage return ASCII character after typing following commands. Carriage return is means that hit enter button in keyboard. 
List commands support: 

RED_LED_ON - Turn on red colour LED  
RED_LED_OFF - Turn off red colour LED 

GREEN_LED_ON - Turn on green colour LED
GREEN_LED_ON - Turn off green colour LED

BLUE_LED_ON - Turn on blue colour LED
BLUE_LED_OFF - Turn off blue colour LED 

ALL_LEDS_ON - Turn on all 3 LEDs
ALL_LEDS_OFF - Turn off all 3 LEDs

Hex value of carrige return - 0x0d.
Decimal value of carrige return - 13.

If you enterred command other than list above, you will receive error message.   

Serial port speed is 115200 bit per second, data frame is 8 bit, stop bit is one and no parity, so please setting to 115200 bps, 8N1, no parity.

UART - Universal asynchronous receiver-transmitter. 
LED -  Light-emitting diode

Viewing repository and licence for related this project: https://github.com/xanthium-enterprises/atmega328p-serial-uart-to-pc-communication

Credit: 
Thanks xanthium-enterprises repositor for understanding and studying how work UART register code. :)

Resource: 
Sreedharan, R. (2019, July 16th). ATmega238p to PC Serial Communication(RX/TX) using USART. Github. https://github.com/xanthium-enterprises/atmega328p-serial-uart-to-pc-communication/blob/master/_1_Serial_Transmit/main.c

Sreedharan, R. (2019, July 16th). ATmega238p to PC Serial Communication(RX/TX) using USART. Github. https://github.com/xanthium-enterprises/atmega328p-serial-uart-to-pc-communication/blob/master/_2_Serial_Receive/main.c

Sreedharan, R. (2019, July 9th). ATmega328P to PC Serial Communication using USART Tutorial. Github. https://www.xanthium.in/how-to-avr-atmega328p-microcontroller-usart-uart-embedded-programming-avrgcc
