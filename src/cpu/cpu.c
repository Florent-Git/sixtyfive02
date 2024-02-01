#include <stdlib.h>
#include "cpu.h"

struct cpu *initialize_cpu() {
    struct cpu *cpu = malloc(sizeof(cpu));
    return cpu;
}

void free_cpu(struct cpu *cpu) {
    free(cpu);
}
