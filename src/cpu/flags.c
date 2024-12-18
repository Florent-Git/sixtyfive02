//
// Created by margaux on 24/02/16.
//

#include "flags.h"

#include <stdio.h>

/**
 * \brief Returns 1 if the overflow flag should be set in consequence
 * of this operation. This is the function version that only serves
 * testing purposes.
 * \param a First operand
 * \param b Second operand
 * \param c Result of the operation
 * \return Whether there is an overflow or not
 */
uint8_t __fn_check_v(uint8_t a, uint8_t b, uint8_t c) {
    a = (a & SIGN_MASK) >> 7;
    b = (b & SIGN_MASK) >> 7;
    c = (c & SIGN_MASK) >> 7;

    printf("~%02X ~%02X %02X | %02X %02X ~%02X\n", !a, !b, c, a, b, !c);

    return !a & !b & c | a & b & !c;
}

uint8_t __fn_check_c(uint8_t a, uint8_t b, uint8_t c) {
    printf("%02X + %02X < MIN(%02X, %02X) || %02X - %02X > MAX(%02X, %02X)\n", a, b, a, b, a, b, a, b);
    printf("%02X < %02X || %02X > %02X\n", c, MIN(a, b), c, MAX(a, b));
    return (c < MIN(a, b)) || (c > MAX(a, b));
}


