/** \file printbase16.c */
/* Author: Markus Wamser, TUEISEC
 */

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>

/**
 * prints data in base16
 * @param data the data to be printed
 * @param len length of the data in uint8_t chunks
 */
uint8_t printbase16(uint8_t const * data, size_t const len) {
    size_t i;
    for (i = 0; i < len; i++) {
        printf("%02x", data[i]);
    }
    printf("\n");
}

void main() {
    uint8_t test[8] = {0x40, 0x60, 0x03, 0xFF, 0xfe, 0x00, 0x01, 0x10};
    printbase16(test, 8);
}
