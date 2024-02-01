#include <stdlib.h>

#include "mem.h"

byte* immediate(
    struct cpu *cpu,
    struct mem *mem,
    byte b1,
    byte b2
) {
    cpu->tmp = b1;
    return &cpu->tmp;
}

byte* abs_addr(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    return mem->pages[b2]->content + b1;
}

byte* zero_page(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    return mem->pages[0]->content + b1;
}

byte* abs_x(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    return abs_addr(cpu, mem, b1 + cpu->regx, b2);
}

byte* abs_y(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    return abs_addr(cpu, mem, b1 + cpu->regy, b2);
}

byte* zero_page_x(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    return zero_page(cpu, mem, b1 + cpu->regx, 0);
}

byte* zero_page_y(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    return zero_page(cpu, mem, b1 + cpu->regy, 0);
}

byte* indirect(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    const byte addr1 = mem->pages[b2]->content[b1];
    const byte addr2 = mem->pages[b2]->content[b1 + 1];
    return abs_addr(cpu, mem, addr1, addr2);
}

byte* pre_indirect(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    const byte addr1 = mem->pages[0]->content[b1 + cpu->regx];
    const byte addr2 = mem->pages[0]->content[b1 + cpu->regx + 1];
    return abs_addr(cpu, mem, addr1, addr2);
}

byte* post_indirect(
    struct cpu* cpu,
    struct mem* mem,
    byte b1,
    byte b2
) {
    const byte addr1 = mem->pages[0]->content[b1];
    const byte addr2 = mem->pages[0]->content[b1 + 1];
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
