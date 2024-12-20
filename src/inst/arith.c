#include "arith.h"

#include <cpu/cpu.h>

#include "../cpu/types.h"
#include "cpu/flags.h"

/*
 ADC
    Add Memory to Accumulator with Carry

    A + M + C -> A, C
    N	Z	C	I	D	V
    +	+	+	-	-	+
    addressing	    assembler	    opc	uint8_ts	cycles
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
    uint8_t *addr
) {
    int16_t value = (int16_t) *addr & 0xFF;
    int16_t result = cpu->rega + value + GET_C(cpu);

    if (result & 0x80) SET_N(cpu);
    else CLEAR_N(cpu);

    if ((result & 0xFF) == 0x00) SET_Z(cpu);
    else CLEAR_Z(cpu);

    if (result & 0x100) SET_C(cpu);
    else CLEAR_C(cpu);

    if (CHECK_V(value & 0x80, cpu->rega & 0x80, result & 0x80)) SET_V(cpu);
    else CLEAR_V(cpu);

    if (GET_D(cpu)) {
        if (IS_ABOVE10HEX(result & 0x0F)) {
            result += 0x06;
        }
        if (IS_ABOVE10HEX((result & 0xF0) >> 8)) {
            result += 0x60;
        }
    }

    cpu->rega = result;
    // arith(cpu, mem, addr, add);
}

/*
SBC
    Subtract Memory from Accumulator with Borrow

    A - M - C̅ -> A
    N	Z	C	I	D	V
    +	+	+	-	-	+
    addressing	    assembler	    opc	uint8_ts	cycles
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
    uint8_t *addr
) {
    uint8_t tmp = ~*addr & 0xFF;
    INVERT_C(cpu);

    int16_t value = (int16_t) tmp & 0xFF;
    int16_t result = cpu->rega + value + GET_C(cpu);

    if (result & 0x80) SET_N(cpu);
    else CLEAR_N(cpu);

    if ((result & 0xFF) == 0x00) SET_Z(cpu);
    else CLEAR_Z(cpu);

    if ((uint8_t) ~tmp + GET_C(cpu) > cpu->rega) SET_C(cpu);
    else CLEAR_BIT(cpu, C);

    if (CHECK_V(value & 0x80, cpu->rega & 0x80, result & 0x80)) SET_V(cpu);
    else CLEAR_V(cpu);

    if (GET_D(cpu)) {
        if (IS_ABOVE10HEX(result & 0x0F)) {
            result -= 0x06;
        }
        if (IS_ABOVE10HEX((result & 0xF0) >> 8)) {
            result -= 0x60;
        }
    }

    cpu->rega = result;

    // arith(cpu, mem, &tmp, sub);
}
