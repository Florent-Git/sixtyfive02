#ifndef INSTRUCTION_TABLE_H
#define INSTRUCTION_TABLE_H
#include <stdlib.h>

#include "../cpu/types.h"

struct inst* initialize_inst_table(void);

struct inst {
    byte inst_code;
    byte inst_len;
    mem_fn inst_mem;
    inst_fn inst;
    struct inst *right;
    struct inst *left;
};

struct inst* insert_inst(struct inst*, byte, byte, mem_fn, inst_fn);
struct inst* create_inst(byte, byte, mem_fn, inst_fn);

const struct inst* search_inst(const struct inst*, const byte);

void free_inst_table(struct inst*);

#endif // INSTRUCTION_TABLE_H
