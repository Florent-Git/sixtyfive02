#ifndef __MEM_H__
#define __MEM_H__

#include "../cpu/types.h"

// These functions converts the addressing to absolute addressing
byte* immediate(struct cpu *cpu, struct mem *mem, byte b1, byte b2);
byte* abs_addr(struct cpu*, struct mem*, byte, byte);
byte* zero_page(struct cpu*, struct mem*, byte, byte);
byte* abs_x(struct cpu*, struct mem*, byte, byte);
byte* abs_y(struct cpu*, struct mem*, byte, byte);
byte* zero_page_x(struct cpu*, struct mem*, byte, byte);
byte* zero_page_y(struct cpu*, struct mem*, byte, byte);
byte* pre_indirect(struct cpu*, struct mem*, byte, byte);
byte* post_indirect(struct cpu*, struct mem*, byte, byte);

struct mem* initialize_memory();
void free_memory(struct mem* mem);

#endif