#ifndef __MEM_H__
#define __MEM_H__

#include "../cpu/types.h"
#include <stdint.h>

// These functions converts the addressing to absolute addressing
uint8_t* immediate(struct cpu *cpu, struct mem *mem, uint8_t b1, uint8_t b2);
uint8_t* abs_addr(struct cpu*, struct mem*, uint8_t, uint8_t);
uint8_t* zero_page(struct cpu*, struct mem*, uint8_t, uint8_t);
uint8_t* abs_x(struct cpu*, struct mem*, uint8_t, uint8_t);
uint8_t* abs_y(struct cpu*, struct mem*, uint8_t, uint8_t);
uint8_t* zero_page_x(struct cpu*, struct mem*, uint8_t, uint8_t);
uint8_t* zero_page_y(struct cpu*, struct mem*, uint8_t, uint8_t);
uint8_t* indirect(struct cpu* cpu, struct mem* mem, uint8_t b1, uint8_t b2);
uint8_t* pre_indirect(struct cpu*, struct mem*, uint8_t, uint8_t);
uint8_t* post_indirect(struct cpu*, struct mem*, uint8_t, uint8_t);

struct mem* initialize_memory();
void free_memory(struct mem* mem);

#endif