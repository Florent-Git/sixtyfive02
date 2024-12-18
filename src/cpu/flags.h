//
// Created by margaux on 24/02/16.
//

#ifndef FLAGS_H
#define FLAGS_H

#include <stdint.h>
#include <sys/param.h>

#define SET_BIT(cpu, bit) ((cpu)->sr = (cpu)->sr | (bit))
#define CLEAR_BIT(cpu, bit) ((cpu)->sr = (cpu)->sr & ~(bit))
#define INVERT_BIT(cpu, bit) ((cpu)->sr = (cpu)->sr ^ (bit))

#define SET_N(cpu) SET_BIT(cpu, N)
#define SET_V(cpu) SET_BIT(cpu, V)
#define SET_B(cpu) SET_BIT(cpu, B)
#define SET_D(cpu) SET_BIT(cpu, D)
#define SET_I(cpu) SET_BIT(cpu, I)
#define SET_Z(cpu) SET_BIT(cpu, Z)
#define SET_C(cpu) SET_BIT(cpu, C)

#define CLEAR_N(cpu) CLEAR_BIT(cpu, N)
#define CLEAR_V(cpu) CLEAR_BIT(cpu, V)
#define CLEAR_B(cpu) CLEAR_BIT(cpu, B)
#define CLEAR_D(cpu) CLEAR_BIT(cpu, D)
#define CLEAR_I(cpu) CLEAR_BIT(cpu, I)
#define CLEAR_Z(cpu) CLEAR_BIT(cpu, Z)
#define CLEAR_C(cpu) CLEAR_BIT(cpu, C)

#define INVERT_N(cpu) INVERT_BIT(cpu, N)
#define INVERT_V(cpu) INVERT_BIT(cpu, V)
#define INVERT_B(cpu) INVERT_BIT(cpu, B)
#define INVERT_D(cpu) INVERT_BIT(cpu, D)
#define INVERT_I(cpu) INVERT_BIT(cpu, I)
#define INVERT_Z(cpu) INVERT_BIT(cpu, Z)
#define INVERT_C(cpu) INVERT_BIT(cpu, C)

#define GET_N(cpu) (cpu->sr & N) >> 7
#define GET_V(cpu) (cpu->sr & V) >> 6
#define GET_B(cpu) (cpu->sr & B) >> 4
#define GET_D(cpu) (cpu->sr & D) >> 3
#define GET_I(cpu) (cpu->sr & I) >> 2
#define GET_Z(cpu) (cpu->sr & Z) >> 1
#define GET_C(cpu) (cpu->sr & C)

#define SIGN_MASK 0x80
#define GET_SIGN(a) ((a & SIGN_MASK) >> 7)

#define CHECK_V(a_sign, b_sign, c_sign) \
    !(a_sign) && !(b_sign) && (c_sign) || \
    (a_sign) && (b_sign) && !(c_sign)

#define CHECK_Z(c) (result & 0xFF) == 0
#define CHECK_N(c) (result & 0x80)

#endif //FLAGS_H
