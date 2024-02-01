//
// Created by margaux on 24/01/30.
//

#ifndef TRANS_H
#define TRANS_H

#include "../cpu/types.h"

void lda(struct cpu *cpu, struct mem *mem, byte *addr);
void ldx(struct cpu *cpu, struct mem *mem, byte *addr);
void ldy(struct cpu *cpu, struct mem *mem, byte *addr);
void sta(struct cpu *cpu, struct mem *mem, byte *addr);
void stx(struct cpu *cpu, struct mem *mem, byte *addr);
void sty(struct cpu *cpu, struct mem *mem, byte *addr);
void tax(struct cpu *cpu, struct mem *mem, byte *addr);
void tay(struct cpu *cpu, struct mem *mem, byte *addr);
void tsx(struct cpu *cpu, struct mem *mem, byte *addr);
void txa(struct cpu *cpu, struct mem *mem, byte *addr);
void txs(struct cpu *cpu, struct mem *mem, byte *addr);
void tya(struct cpu *cpu, struct mem *mem, byte *addr);

#endif //TRANS_H
