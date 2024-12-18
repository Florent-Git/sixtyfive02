//
// Created by margaux on 24/01/30.
//

#include "trans.h"

void lda(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->rega = *addr;
    
}

void ldx(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->regx = *addr;
}

void ldy(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->regy = *addr;
}

void sta(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    *addr = cpu->rega;
}

void stx(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    *addr = cpu->regx;
}

void sty(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    *addr = cpu->regy;
}

void tax(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->regx = cpu->rega;
}

void tay(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->regy = cpu->rega;
}

void tsx(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->regx = cpu->sp;
}

void txa(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->rega = cpu->regx;
}

void txs(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->sp = cpu->regx;
}

void tya(struct cpu *cpu, struct mem *mem, uint8_t *addr) {
    cpu->rega = cpu->regy;
}
