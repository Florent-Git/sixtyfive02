#include "arith.h"
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
void adc(struct cpu *cpu, struct mem *mem, byte *addr) {
    short value = ((short) *addr) & 0xFF;
    short result = cpu->rega + value + (cpu->sr & 1);
    if (result > 0xFF) cpu->sr |= 1;
    else cpu->sr &= 0b11111110;
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
void sbc(struct cpu *cpu, struct mem *mem, byte *addr) {

}