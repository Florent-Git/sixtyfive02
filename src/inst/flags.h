//
// Created by margaux on 24/02/09.
//

#ifndef FLAGS_H
#define FLAGS_H

#include <cpu/types.h>
#include <cpu/cpu.h>

void clc(struct cpu *cpu, struct mem *mem, byte *addr);
void cld(struct cpu *cpu, struct mem *mem, byte *addr);
void cli(struct cpu *cpu, struct mem *mem, byte *addr);
void clv(struct cpu *cpu, struct mem *mem, byte *addr);
void sec(struct cpu *cpu, struct mem *mem, byte *addr);
void sed(struct cpu *cpu, struct mem *mem, byte *addr);
void sei(struct cpu *cpu, struct mem *mem, byte *addr);


#endif //FLAGS_H
