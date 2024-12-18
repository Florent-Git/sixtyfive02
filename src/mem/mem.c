#include <stdlib.h>

#include "mem.h"

uint8_t* immediate(
    struct cpu *cpu,
    struct mem *mem,
    uint8_t b1,
    uint8_t b2
) {
    cpu->tmp = b1;
    return &cpu->tmp;
}

uint8_t* abs_addr(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    return mem->pages[b2]->content + b1;
}

uint8_t* zero_page(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    return mem->pages[0]->content + b1;
}

uint8_t* abs_x(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    return abs_addr(cpu, mem, b1 + cpu->regx, b2);
}

uint8_t* abs_y(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    return abs_addr(cpu, mem, b1 + cpu->regy, b2);
}

uint8_t* zero_page_x(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    return zero_page(cpu, mem, b1 + cpu->regx, 0);
}

uint8_t* zero_page_y(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    return zero_page(cpu, mem, b1 + cpu->regy, 0);
}

uint8_t* indirect(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    const uint8_t addr1 = mem->pages[b2]->content[b1];
    const uint8_t addr2 = mem->pages[b2]->content[b1 + 1];
    return abs_addr(cpu, mem, addr1, addr2);
}

uint8_t* pre_indirect(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    const uint8_t addr1 = mem->pages[0]->content[b1 + cpu->regx];
    const uint8_t addr2 = mem->pages[0]->content[b1 + cpu->regx + 1];
    return abs_addr(cpu, mem, addr1, addr2);
}

uint8_t* post_indirect(
    struct cpu* cpu,
    struct mem* mem,
    uint8_t b1,
    uint8_t b2
) {
    const uint8_t addr1 = mem->pages[0]->content[b1];
    const uint8_t addr2 = mem->pages[0]->content[b1 + 1];
    return abs_addr(cpu, mem, addr1 + cpu->regy, addr2);
}

struct mem* initialize_memory() {
    struct mem* mem = malloc(sizeof(struct mem));

    for (int i = 0; i < PAGE_COUNT; ++i) {
        mem->pages[i] = malloc(sizeof(struct page));
        for (int j = 0; j < PAGE_SIZE; ++j) {
            mem->pages[i]->content[j] = 0;
        }
    }

    return mem;
}

void free_memory(struct mem* mem) {
    free(mem);
}
