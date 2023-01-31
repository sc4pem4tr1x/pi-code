// * Library initialisation and management
// Created by sc4pem4tr1x on 1/31/23.
//

#include <bcm2835.h>

// Close the library, deallocating any allocated memory and closing /dev/mem
bcm2835_close();
// returns 1 if successful. else 0


/*
 * Initialize the library. You MUST call this (successfully) before calling any other functions in this library
 * (except bcm2835_set_debug). If calling this function fails, returning a 0, calling any other functions
 * could result in crashes or other failures
 */
bcm2835_init();
// Returns 1 if successful. else 0

/*
 * Sets the debug level of the library. A value of 1 prevents mapping to /dev/mem, and makes the library
 * print out what it would do, rather than accessing the GPIO registers. A value of 0, the default, causes
 * normal operation. Call this before calling bcm2835_init();
 */
bcm2835_set_debug(); // params: [int] debug. The new debug level. 1 means debug


// Returns the version number of the library, same as BCM2835_VERSION
bcm2835_version();
// Returns the current library version number
