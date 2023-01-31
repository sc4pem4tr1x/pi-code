//
// Created by sc4pem4tr1x on 1/31/23.
//

#include <bcm2835.h>

/*
 * Sets the Function Select register for the given pin, which configures the pin as Input,
 * Output or one of the 6 alternate functions.
 */
bcm2835_gpio_fsel();
/*
 * Params:
 *      [int] pin - GPIO number, or one of RPI_GPIO_P1_* from RPiGPIOPin.
 *      [int] mode - Mode to set the pin to, one of BCM2835_GPIO_FSEL_* from bcm2835FunctionSelect
 */


/*
 * On the BCM2711 based RPI 4, gets the current Pull-up/down mode for the specified pin. Returns
 * one of BCM2835_GPIO_PUD_* from bcm2835PUDControl. On earlier RPI versions not based on the BCM2711,
 * returns BCM2835_GPIO_PUD_ERROR
 */
bcm2835_gpio_get_pud();