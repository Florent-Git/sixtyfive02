#include <stdio.h>
#include <cpu/cpu.h>
#include <inst/arith.h>

#include <cpu/flags.c>

#define DEBUG

void dump_cpu(struct cpu *cpu) {
    printf("----- CPU DUMP -----\n");
    printf("Register X:\t\t\t%02x\n", cpu->regx);
    printf("Register Y:\t\t\t%02x\n", cpu->regy);
    printf("Register A:\t\t\t%02x\n", cpu->rega);
    printf("Stack Pointer:\t\t%02x\n", cpu->sp);

    printf("\t\t\t\t\tNV-B DIZC\n");
    printf("Status register:\t");
    for (int i = 7; i >= 0; --i) {
        printf("%d", (cpu->sr & (1 << i)) >> i);
        if (i == 4) printf(" ");
    }
    printf(" (%02x)\n", cpu->sr);

    printf("Program counter:\t%04x\n", cpu->pc);
    printf("----- END OF CPU DUMP -----\n");
}

int main() {
    struct cpu *cpu = initialize_cpu();
    struct mem *mem = initialize_memory();

    uint8_t a = 0x09;

    dump_cpu(cpu);

    SET_D(cpu);

    dump_cpu(cpu);

    cpu->rega = 0x02;

    dump_cpu(cpu);

    adc(cpu, mem, &a);

    dump_cpu(cpu);

    printf("%02x", cpu->rega);

    return 0;
}
