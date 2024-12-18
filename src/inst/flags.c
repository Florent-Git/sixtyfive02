//
// Created by margaux on 24/02/09.
//

#include <cpu/flags.h>
#include <cpu/types.h>

void clc(struct cpu *cpu, struct mem *, uint8_t *) {
    CLEAR_C(cpu);
}

void cld(struct cpu *cpu, struct mem *, uint8_t *) {
    CLEAR_D(cpu);
}

void cli(struct cpu *cpu, struct mem *, uint8_t *) {
    CLEAR_I(cpu);
}

void clv(struct cpu *cpu, struct mem *, uint8_t *) {
    CLEAR_V(cpu);
}

void sec(struct cpu *cpu, struct mem *, uint8_t *) {
    SET_C(cpu);
}

void sed(struct cpu *cpu, struct mem *, uint8_t *) {
    SET_D(cpu);
}

void sei(struct cpu *cpu, struct mem *, uint8_t *) {
    SET_I(cpu);
}
