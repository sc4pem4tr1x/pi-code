// blink.c
// Created by the-dicktator on 1/30/23.
// A pretty epic program.

/*
 * Blinks a pin on and off every 0.5 secs
 * build with gcc -o ./builds/blink blink.c -l bcm2835
 */

/*
 * To install the libary use
 * sudo wget https://www.airspayce.com/mikem/bcm2835/bcm2835-1.71.tar.gz
 * tar zxvf bcm2835-1.xx.tar.gz
 * cd bcm2835-1.xx
 * ./configure
 * make
 * sudo make check
 * sudo make install
 */

#include <bcm2835.h>
#include <stdio.h>

// Blinks on the RPi Plug P1 pin 11 (which is GPIO pin 17)
#define PIN RPI_GPIO_P1_11

int main(int argc, char **argv)
{
    //If you call this, it will not actually access the GPIO
    //Use for testing
    //bcm2835_set_debug(1)

    if (!bcm2835_init())
        return 1;

    // Set the pin to be an output
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_OUTP);

    int delay = 500;
    //Blink
    while (1)
    {
        // Turn it on
        bcm2835_gpio_write(PIN, HIGH);
        // Wait a bit
        bcm2835_delay(delay);
        // Turn it off
        bcm2835_gpio_write(PIN, LOW);
        // Wait a bit
        bcm2835_delay(delay);
    }
    bcm2835_close()
    return 0;

    printf();
}