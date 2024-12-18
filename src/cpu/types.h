#ifndef __TYPES_H__
#define __TYPES_H__

#include <stdint.h>

#define PAGE_COUNT  256
#define PAGE_SIZE   256

short btos(uint8_t, uint8_t);

#define N 1 << 7
#define V 1 << 6
#define B 1 << 4
#define D 1 << 3
#define I 1 << 2
#define Z 1 << 1
#define C 1

struct cpu {
    // 3 8-bit registers
    uint8_t regx;
    uint8_t regy;
    uint8_t rega;

    // 8-bit stack pointer
    uint8_t sp;

    // 8-bit status register
    uint8_t sr;

    // 16-bit program counter
    uint16_t pc;

    // Temp memory buffer
    uint8_t tmp;
};

struct page {
    uint8_t content[PAGE_SIZE];
};

struct mem {
    struct page *pages[PAGE_COUNT];
};

typedef void(*inst_fn)(struct cpu*, struct mem*, uint8_t*);
typedef uint8_t*(*mem_fn)(struct cpu*, struct mem*, uint8_t, uint8_t);

#endif