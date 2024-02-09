#ifndef __CPU_H__
#define __CPU_H__

#include "types.h"

#define set_bit(cpu, bit) cpu->sr = cpu->sr | bit
#define clear_bit(cpu, bit) cpu->sr = cpu->sr ^ (~bit & 0xFF)
#define invert_bit(cpu, bit) cpu->sr = cpu->sr ^ bit

#define set_N(cpu) set_bit(cpu, N)
#define set_V(cpu) set_bit(cpu, V)
#define set_B(cpu) set_bit(cpu, B)
#define set_D(cpu) set_bit(cpu, D)
#define set_I(cpu) set_bit(cpu, I)
#define set_Z(cpu) set_bit(cpu, Z)
#define set_C(cpu) set_bit(cpu, C)

#define clear_N(cpu) clear_bit(cpu, N)
#define clear_V(cpu) clear_bit(cpu, V)
#define clear_B(cpu) clear_bit(cpu, B)
#define clear_D(cpu) clear_bit(cpu, D)
#define clear_I(cpu) clear_bit(cpu, I)
#define clear_Z(cpu) clear_bit(cpu, Z)
#define clear_C(cpu) clear_bit(cpu, C)

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