#ifndef __CPU_H__
#define __CPU_H__

#include "types.h"

struct cpu *initialize_cpu();
void free_cpu(struct cpu *cpu);

#ifdef DEBUG

void print_debug(struct cpu *cpu);

#endif

#endif