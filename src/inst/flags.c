//
// Created by margaux on 24/02/09.
//

#include "flags.h"

void clc(struct cpu *cpu, struct mem *, byte *) {
    clear_C(cpu);
}

void cld(struct cpu *cpu, struct mem *, byte *) {
    clear_D(cpu);
}

void cli(struct cpu *cpu, struct mem *, byte *) {
    clear_I(cpu);
}

void clv(struct cpu *cpu, struct mem *, byte *) {
    clear_V(cpu);
}

void sec(struct cpu *cpu, struct mem *, byte *) {
    set_C(cpu);
}

void sed(struct cpu *cpu, struct mem *, byte *) {
    set_D(cpu);
}

void sei(struct cpu *cpu, struct mem *, byte *) {
    set_I(cpu);
}
