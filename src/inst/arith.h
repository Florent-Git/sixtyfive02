#ifndef __ADC_H__
#define __ADC_H__

#include "../mem/mem.h"

#define IS_ABOVE10HEX(x) (((x) & 0b1000) >> 3 & (((x) & 0b100) >> 2 | ((x) & 0b10) >> 1))

typedef enum op { add, sub } op_t;

void adc(struct cpu *cpu, struct mem *mem, uint8_t *addr);
void sbc(struct cpu *cpu, struct mem *mem, uint8_t *addr);

#endif