#include "arith.h"

#include <cpu/cpu.h>

#include "../cpu/types.h"

/*
 ADC
    Add Memory to Accumulator with Carry

    A + M + C -> A, C
    N	Z	C	I	D	V
    +	+	+	-	-	+
    addressing	    assembler	    opc	bytes	cycles
    immediate	    ADC #oper	    69	2	    2  
    zeropage	    ADC oper	    65	2	    3  
    zeropage,X	    ADC oper,X	    75	2	    4  
    absolute	    ADC oper	    6D	3	    4  
    absolute,X	    ADC oper,X	    7D	3	    4* 
    absolute,Y	    ADC oper,Y	    79	3	    4* 
    (indirect,X)	ADC (oper,X)	61	2	    6  
    (indirect),Y	ADC (oper),Y	71	2	    5* 
*/
void adc(
    struct cpu *cpu,
    struct mem *mem,
    byte *addr
) {
    short value = (short) *addr & 0xFF;
    short result = cpu->rega + value + get_C(cpu);

    if (((cpu->rega ^ result) & (value ^ result) & 0x80) != 0) {
        set_V(cpu);
    } else {
        clear_V(cpu);
    }

    if (result & 0x100) {
        set_C(cpu);
    } else {
        clear_C(cpu);
    }

    if ((result & 0xFF) == 0) {
        set_Z(cpu);
    } else {
        clear_Z(cpu);
    }

    if (result & 0x80) {
        set_N(cpu);
    } else {
        clear_N(cpu);
    }

    cpu->rega = result;
}

/*
SBC
    Subtract Memory from Accumulator with Borrow

    A - M - C̅ -> A
    N	Z	C	I	D	V
    +	+	+	-	-	+
    addressing	    assembler	    opc	bytes	cycles
    immediate	    SBC #oper	    E9	2	    2
    zeropage	    SBC oper	    E5	2	    3
    zeropage,X	    SBC oper,X	    F5	2	    4
    absolute	    SBC oper	    ED	3	    4
    absolute,X	    SBC oper,X	    FD	3	    4*
    absolute,Y	    SBC oper,Y	    F9	3	    4*
    (indirect,X)	SBC (oper,X)	E1	2	    6
    (indirect),Y	SBC (oper),Y	F1	2	    5*
*/
void sbc(
    struct cpu *cpu,
    struct mem *mem,
    byte *addr
) {
    cpu->tmp = ~*addr & 0xFF;
    invert_C(cpu);
    adc(cpu, mem, &cpu->tmp);


}