// GPIO Inputs
// Created by sc4pem4tr1x on 1/31/23.
//

/*
 * - Polling
 *      * Program periodically checks for input
 *      * The input must be present when the polling occurs
 * - Interrupt
 *      * Real interrupts will interrupt the processor
 *        as soon as they are triggered
 *      * In this demonstration, the "Interrupt" only sets
 *        a flag that an input has been detected
 */

// ! Build with gcc -o reading-gpio reading-gpio.c -l bcm2835

#include <stdio.h>
#include <bcm2835.h>

#define LED 18
#define BUTTON_1 19
#define BUTTON_2 26
#define DELAY_CHANGE 500
#define ONE_BIT_MASK 0x1

int main(int argc, char **argv)
{
    //This line initializes bcm2835 library
    if (!bcm2835_init())
        return 1;

    bcm2835_gpio_fsel(LED, BCM2835_GPIO_FSEL_OUTP); // Sets the LED to output
    bcm2835_gpio_fsel(BUTTON_1, BCM2835_GPIO_FSEL_INPT); // Sets the button1 to input
    bcm2835_gpio_fsel(BUTTON_1, BCM2835_GPIO_PUD_UP); // Enable pull up
    bcm2835_gpio_fsel(BUTTON_2, BCM2835_GPIO_FSEL_INPT); // Sets button2 to input
    bcm2835_gpio_fsel(BUTTON_2, BCM2835_GPIO_PUD_UP); // Enable pull up

    bcm2835_gpio_len(BUTTON_1); // Enable low detect on Button 1

    unsigned int delay = 5000;

    while (1)
    {
        // Check for button1 press
        if (bcm2835_gpio_eds(BUTTON_1))
        {
            printf("Button 1: ON | ");
            delay = delay - DELAY_CHANGE; // decreases delay
            bcm2835_gpio_set_eds(BUTTON_1); // clear flag
        } else {
            printf("Button 1: OFF | ");
        }

        // Check for button 2 press
        if (bcm2835_gpio_lev(BUTTON_2) == LOW)
        {
            printf("Button 2: OFF |");
            delay = delay + DELAY_CHANGE; // Increases delay
        } else {
            printf("Button 2: OFF | ");
        }
        printf("Delay: %d ms\n", delay);
        bcm2835_gpio_write(LED, bcm2835_gpio_lev(LED)^ONE_BIT_MASK); // Toggle led
        bcm2835_delay(delay); // wait for delay ms
    }

    return 0;
}