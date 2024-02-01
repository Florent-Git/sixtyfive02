#include <stdio.h>

#include "cpu/cpu.h"
#include "mem/mem.h"
#include "inst/instruction_table.h"

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

int main(int argc, char **argv) {
    struct cpu* cpu = initialize_cpu();
    struct mem* mem = initialize_memory();
    struct inst* inst = initialize_inst_table();

    execute_instruction(cpu, mem, inst, 0x69, 0x07, 0x00);
    printf("Immediate: %02X\n", cpu->rega);

    cpu->rega = 0;

    mem->pages[0]->content[0x69] = 0xFD;
    execute_instruction(cpu, mem, inst, 0x65, 0x69, 0x00);
    printf("Zero-page: %02X\n", cpu->rega);

    cpu->rega = 0;

    mem->pages[0]->content[0x6D] = 0xAB;
    cpu->regx = 0x04;
    execute_instruction(cpu, mem, inst, 0x75, 0x69, 0x00);
    printf("Zero-page X: %02X\n", cpu->rega);

    cpu->rega = 0;

    mem->pages[0xAB]->content[0xCD] = 0xF1;
    execute_instruction(cpu, mem, inst, 0x6D, 0xCD, 0xAB);
    printf("Absoulte: %02X\n", cpu->rega);

    cpu->rega = 0;

    mem->pages[0xAB]->content[0xD1] = 0xDD;
    cpu->regx = 0x04;
    execute_instruction(cpu, mem, inst, 0x7D, 0xCD, 0xAB);
    printf("Absoulte X: %02X\n", cpu->rega);

    cpu->rega = 0;

    mem->pages[0xAB]->content[0xD2] = 0xEE;
    cpu->regy = 0x05;
    execute_instruction(cpu, mem, inst, 0x79, 0xCD, 0xAB);
    printf("Absoulte Y: %02X\n", cpu->rega);

    cpu->rega = 0;

    mem->pages[0x00]->content[0x17] = 0x34;
    mem->pages[0x00]->content[0x18] = 0x56;
    mem->pages[0x56]->content[0x34] = 0x1C;
    cpu->regx = 0x05;
    execute_instruction(cpu, mem, inst, 0x61, 0x12, 0x00);
    printf("Indirect X: %02X\n", cpu->rega);

    cpu->rega = 0;

    mem->pages[0x00]->content[0x12] = 0x34;
    mem->pages[0x00]->content[0x13] = 0x56;
    mem->pages[0x56]->content[0x3A] = 0xC1;
    cpu->regy = 0x06;
    execute_instruction(cpu, mem, inst, 0x71, 0x12, 0x00);
    printf("Indirect Y: %02X\n", cpu->rega);

    free_inst_table(inst);
    free_memory(mem);
    free_cpu(cpu);
}