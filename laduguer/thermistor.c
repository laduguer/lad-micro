/*
 * Inspirations from:
 *  - https://www.jameco.com/Jameco/workshop/techtip/temperature-measurement-ntc-thermistors.html
 *  - https://www.ametherm.com/blog/thermistor/arduino-and-thermistors
 *  - https://www.marcelpost.com/wiki/index.php/ATtiny85_ADC
 *  - https://github.com/clockfort/AVR-Thermistor/blob/master/thermistor.c
 *
 *  Using NXRT15XV103FA1B040 thermistor on PB4. With 10k 5% resistor.
 *
 *  Basic Schematic:
 *
 *      GND --- 10K ohm normal resistor ---|--- 10K ohm thermistor ---- VCC
 *  	    			                   |
 *  		    		            Microcontroller ADC (PB4)
 */

#include "thermistor.h"
#include <avr/io.h>
#include <math.h>


void initADC() {
    ADMUX =
            (0 << ADLAR) |      // left shift
            (0 << REFS1) |      // Sets ref. voltage to VCC, bit 1
            (0 << REFS0) |      // Sets ref. voltage to VCC, bit 0
            (0 << MUX3) |       // use ADC2 for input (PB4), MUX bit 3
            (0 << MUX2) |       // use ADC2 for input (PB4), MUX bit 2
            (1 << MUX1) |       // use ADC2 for input (PB4), MUX bit 1
            (0 << MUX0);        // use ADC2 for input (PB4), MUX bit 0

    ADCSRA =
            (1 << ADEN) |       // Enable ADC
            (1 << ADPS2) |      // set prescaler to 64, bit 2
            (1 << ADPS1) |      // set prescaler to 64, bit 1
            (0 << ADPS0);       // set prescaler to 64, bit 0

}


float readTemperature() {
    uint8_t adc_lobyte; // to hold the low byte of the ADC register (ADCL)
    uint16_t raw_adc;

    ADCSRA |= (1 << ADSC);         // start ADC measurement
    while (ADCSRA & (1 << ADSC)); // wait till conversion complete

    // for 10-bit resolution:
    adc_lobyte = ADCL; // get the sample value from ADCL
    raw_adc = ADCH<<8 | adc_lobyte;   // add lobyte and hibyte

    float temp = 0;
    float res = raw_adc;
    temp =  (1.00 / ((1.00/(25.00+273.15)) + ((1.00/3936.00) * log( (1023.00 / res) - 1 )))) - 273.15;

    return temp;

}