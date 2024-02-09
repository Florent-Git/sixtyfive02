#ifndef __ADC_H__
#define __ADC_H__

#include "../mem/mem.h"

void adc(struct cpu *cpu, struct mem *mem, byte *addr);
void sbc(struct cpu *cpu, struct mem *mem, byte *addr);

#endif