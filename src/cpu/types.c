#include <stdlib.h>

#include "types.h"

short btos(uint8_t b1, uint8_t b2) {
    uint8_t *arr = (uint8_t*) malloc(2 * sizeof(uint8_t));
    arr[0] = b1;
    arr[1] = b2;
    return *((short*) arr);
}
