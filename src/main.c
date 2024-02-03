#include <stdio.h>
#include <cpu/cpu.h>
#include <inst/arith.h>

int main() {
    struct cpu *cpu = initialize_cpu();
    struct mem *mem = initialize_memory();

    cpu->rega = 200;
    byte b = 100;
    // Example causing overflow
    adc(cpu, mem, &b);  // Adding 0xFF to the accumulator
    printf("Register A: %02X\n", cpu->rega);

    // Check Overflow and Carry Flags
    if (cpu->sr & 0x40) {
        printf("Overflow Flag (V) is set.\n");
    } else {
        printf("Overflow Flag (V) is not set.\n");
    }

    if (cpu->sr & 0x01) {
        printf("Carry Flag (C) is set.\n");
    } else {
        printf("Carry Flag (C) is not set.\n");
    }

    free_cpu(cpu);

    return 0;
}
