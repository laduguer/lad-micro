/*  Software ("bit-bang") UART Transmitter (8 data bits, 1 stop bit, no parity)
    for Attiny24A/44A/84A using the internal 8MHz oscillator as clock source

    (c) 2018 Marcel Meyer-Garcia
    see LICENCE.txt
 */

/* NOTE: since the internal 8MHz oscillator is not very accurate, the value for OCR0A can be tuned
   to achieve the desired baud rate (nominal value is 103)
*/

#include "laduguer/serial.h"
#include <util/delay.h>

int main(void)
{
    begin();
    while(1)
    {
        sendString("Hi there!\n");
        _delay_ms(500);
    }
    return 0;
}
