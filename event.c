// event.c
// Created by the-dicktator on 1/30/23.
//

/*
 * Event detection of an input pin
 * build with:
 * gcc -o ./builds/event event.c -l bcm2835
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

/*
 * Allow write access to /deb/mem by members of kmem group
 * echo 'SUBSYSTEM=="mem", KERNEL=="mem", GROUP="kmem", MODE="0660"' | sudo tee /etc/udev/rules.d/98-mem.rules
 * sudo reboot
 */

#include <bcm2835.h>
#include <stdio.h

// Input on RPi pin GPIO 15
#define PIN RPI_GPIO_P1_15

int main(int argc, char **argv)
{
    // If you call this, it will not actually access the GPIO
    // Use for testing
    // bcm2835_set_debug(1)

    if (!bcm2835_init())
        return 1;

    // Set RPI pin P1-15 to be an input
    bcm2835_gpio_fsel(PIN, BCM2835_GPIO_FSEL_INPT);
    // with a pullup
    bcm2835_gpio_set_pud(PIN, BCM2835_GPIO_PUD_UP);
    // And a low detect enable
    bcm2835_gpio_len(PIN);

    while (1)
    {
        if (bcm2835_gpio_eds(PIN))
        {
            // Now clear the eds flag by setting it to 1
            bcm2835_gpio_set_eds(PIN);
            pritnf("Low event detect for pin 15\n");
        }

        // wait a bit
        delay(500);
    }
    bcm2835_close();
    return 0;
}





