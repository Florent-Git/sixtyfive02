#ifndef __TYPES_H__
#define __TYPES_H__

#define PAGE_COUNT  256
#define PAGE_SIZE   256

typedef unsigned char byte;

short btos(byte, byte);

enum {
    N = 1 << 7,
    V = 1 << 6,
    _ = 1 << 5,
    B = 1 << 4,
    D = 1 << 3,
    I = 1 << 2,
    Z = 1 << 1,
    C = 1 << 0,
};

struct cpu {
    // 3 8-bit registers
    byte regx;
    byte regy;
    byte rega;

    // 8-bit stack pointer
    byte sp;

    // 8-bit status register
    byte sr;

    // 16-bit program counter
    unsigned short pc;

    // Temp memory buffer
    byte tmp;
};

struct page {
    byte content[PAGE_SIZE];
};

struct mem {
    struct page *pages[PAGE_COUNT];
};

typedef void(*inst_fn)(struct cpu*, struct mem*, byte*);
typedef byte*(*mem_fn)(struct cpu*, struct mem*, byte, byte);

#endif