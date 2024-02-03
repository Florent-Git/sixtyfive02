#ifndef __CPU_H__
#define __CPU_H__

#include "types.h"

#define enable_bit(cpu, bit) cpu->sr |= bit
#define disable_bit(cpu, bit) cpu->sr &= (~bit & 0xFF)
#define invert_bit(cpu, bit) cpu->sr ^ bit

#define enable_N(cpu) enable_bit(cpu, N)
#define enable_V(cpu) enable_bit(cpu, V)
#define enable_B(cpu) enable_bit(cpu, B)
#define enable_D(cpu) enable_bit(cpu, D)
#define enable_I(cpu) enable_bit(cpu, I)
#define enable_Z(cpu) enable_bit(cpu, Z)
#define enable_C(cpu) enable_bit(cpu, C)

#define disable_N(cpu) disable_bit(cpu, N)
#define disable_V(cpu) disable_bit(cpu, V)
#define disable_B(cpu) disable_bit(cpu, B)
#define disable_D(cpu) disable_bit(cpu, D)
#define disable_I(cpu) disable_bit(cpu, I)
#define disable_Z(cpu) disable_bit(cpu, Z)
#define disable_C(cpu) disable_bit(cpu, C)

#define invert_N(cpu) invert_bit(cpu, N)
#define invert_V(cpu) invert_bit(cpu, V)
#define invert_B(cpu) invert_bit(cpu, B)
#define invert_D(cpu) invert_bit(cpu, D)
#define invert_I(cpu) invert_bit(cpu, I)
#define invert_Z(cpu) invert_bit(cpu, Z)
#define invert_C(cpu) invert_bit(cpu, C)

#define get_N(cpu) (cpu->sr & N) >> 7
#define get_V(cpu) (cpu->sr & V) >> 6
#define get_B(cpu) (cpu->sr & B) >> 4
#define get_D(cpu) (cpu->sr & D) >> 3
#define get_I(cpu) (cpu->sr & I) >> 2
#define get_Z(cpu) (cpu->sr & Z) >> 1
#define get_C(cpu) (cpu->sr & C)

struct cpu *initialize_cpu();
void free_cpu(struct cpu *cpu);

#endif