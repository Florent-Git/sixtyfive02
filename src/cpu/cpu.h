#ifndef __CPU_H__
#define __CPU_H__

#include "types.h"

struct cpu *initialize_cpu();
void free_cpu(struct cpu *cpu);

#endif