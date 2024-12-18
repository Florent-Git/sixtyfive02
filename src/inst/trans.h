//
// Created by margaux on 24/01/30.
//

#ifndef TRANS_H
#define TRANS_H

#include "../cpu/types.h"

void lda(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void ldx(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void ldy(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void sta(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void stx(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void sty(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void tax(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void tay(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void tsx(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void txa(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void txs(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void tya(struct cpu *cpu, struct mem *mem, uint8_t *addr);

#endif //TRANS_H
