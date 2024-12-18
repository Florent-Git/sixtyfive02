#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H
#include <stdlib.h>

#include "../cpu/types.h"

struct inst* initialize_inst_table(void);

struct inst {
    uint8_t inst_code;
    uint8_t inst_len;
    uint8_t inst_cycles;
    mem_fn inst_mem;
    inst_fn inst;
    struct inst *right;
    struct inst *left;
};

struct inst* insert_inst(struct inst*, uint8_t, uint8_t, uint8_t, mem_fn, inst_fn);
struct inst* create_inst(uint8_t, uint8_t, uint8_t, mem_fn, inst_fn);

const struct inst* search_inst(const struct inst*, const uint8_t);

void free_inst_table(struct inst*);

void execute_instruction(
    struct cpu *cpu,
    struct mem *mem,
    struct inst *table,
    uint8_t opcode,
    uint8_t oper1,
    uint8_t oper2
);

#endif // INSTRUCTION_TABLE_H
