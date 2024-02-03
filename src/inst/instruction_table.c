#include "instruction_table.h"

#include "arith.h"

struct inst* insert_inst(
    struct inst* root,
    const byte instruction_code,
    const byte inst_len,
    const byte inst_cycles,
    const mem_fn mem_fn,
    const inst_fn inst
) {
    if (root == NULL) {
        return create_inst(instruction_code, inst_len, inst_cycles, mem_fn, inst);
    }
    if (instruction_code < root->inst_code) {
        root->left = insert_inst(root->left, instruction_code, inst_len, inst_cycles, mem_fn, inst);
    }
    else if (instruction_code > root->inst_code) {
        root->right = insert_inst(root->right, instruction_code, inst_len, inst_cycles, mem_fn, inst);
    }
    return root;
}

struct inst* create_inst(
    const byte instruction_code,
    const byte inst_len,
    const byte inst_cycles,
    const mem_fn mem_fn,
    const inst_fn inst
) {
    struct inst* new_inst = malloc(sizeof(struct inst));
    new_inst->inst_code = instruction_code;
    new_inst->inst_len = inst_len;
    new_inst->inst_mem = mem_fn;
    new_inst->right = NULL;
    new_inst->left = NULL;
    new_inst->inst = inst;
    new_inst->inst_cycles = inst_cycles;
    return new_inst;
}

const struct inst* search_inst(
    const struct inst* root,
    const byte instruction_code
) {
    if (root->inst_code == instruction_code) {
        return root;
    }

    if (root->inst_code < instruction_code) {
        return search_inst(root->right, instruction_code);
    }

    return search_inst(root->left, instruction_code);
}

void free_inst_table(
    struct inst* root
) {
    if (root != NULL) {
        free_inst_table(root->left);
        free_inst_table(root->right);
        free(root);
    }
}

struct inst* initialize_inst_table() {
    struct inst* root = create_inst(0, 0, 0, NULL, NULL);

    insert_inst(root, 0x69, 2, 2, immediate, adc);
    insert_inst(root, 0x65, 2, 3, zero_page, adc);
    insert_inst(root, 0x75, 2, 4, zero_page_x, adc);
    insert_inst(root, 0x6D, 3, 4, abs_addr, adc);
    insert_inst(root, 0x7D, 3,4, abs_x, adc);
    insert_inst(root, 0x79, 3, 4, abs_y, adc);
    insert_inst(root, 0x61, 2, 6, pre_indirect, adc);
    insert_inst(root, 0x71, 2, 5, post_indirect, adc);

    return root;
}

void execute_instruction(
    struct cpu *cpu,
    struct mem *mem,
    struct inst *table,
    byte opcode,
    byte oper1,
    byte oper2
) {
    const struct inst* inst = search_inst(table, opcode);
    byte *addr = inst->inst_mem(cpu, mem, oper1, oper2);
    inst->inst(cpu, mem, addr);
}
