#include <stdlib.h>
#include "cpu.h"

struct cpu *initialize_cpu() {
    struct cpu *cpu = malloc(sizeof(cpu));
    cpu->pc = 0;
    cpu->rega = 0;
    cpu->regx = 0;
    cpu->regy = 0;
    cpu->sp = 0;
    cpu->sr = 0;
    cpu->tmp = 0;
    return cpu;
}

void free_cpu(struct cpu *cpu) {
    free(cpu);
}

