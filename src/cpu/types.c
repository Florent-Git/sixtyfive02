#include <stdlib.h>

#include "types.h"

short btos(byte b1, byte b2) {
    byte *arr = (byte*) malloc(2 * sizeof(byte));
    arr[0] = b1;
    arr[1] = b2;
    return *((short*) arr);
}
