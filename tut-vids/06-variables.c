// Variables
// Created by sc4pem4tr1x on 1/31/23.
//

#include <stdio.h>
#include <limits.h>

// Function Declarations
char findCharMinMax(char[4]);
int findIntMinMax(char[4]);
unsigned int findUintMax(void);

int main(int argc, char **argv)
{
    /*
     * A char is 1 byte. 1 byte = 8 bits which means it can have
     * 2^8 possible values. Remember 2^n for later.
     */

    char oneByteMax = 255;
    char oneByteMin;
    oneByteMin = 0;
    char anotherByte;
    anotherByte = oneByteMax / 2;

    /*
     * A String
     * The char can hold characters
     * and an array of char can hold a string
     * of characters as follows
     */

    char aChar[5] = {'c', 'h', 'a', 'r', '\0'};
    char min[] = "min";

    return 0;
}





