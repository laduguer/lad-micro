#include "laduguer/serial.h"
#include "laduguer/thermistor.h"
#include <util/delay.h>

int main(void) {
    begin();
    initADC();

    char buff[64];

    while (1) {
        sendString("-Sensor-\n");

        sendString("Temperature is: ");
        sendString(dtostrf(readTemperature(), 0, 3, buff));
        sendString(" C\n");

        sendString("--------\n\n\n");

        _delay_ms(500);
    }


    return 0;
}