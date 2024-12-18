#include <gtest/gtest.h>

extern "C" {
#include <cpu/cpu.h>
#include <cpu/flags.h>
#include <mem/mem.h>
#include <inst/arith.h>
}

class InstructionTests : public testing::Test {
protected:
    InstructionTests() {
        this->cpu = initialize_cpu();
        this->mem = initialize_memory();
    }

    struct cpu *cpu;
    struct mem *mem;
};

TEST_F(InstructionTests, AdditionSimple) {
    uint8_t b = 0x07;
    cpu->rega = 0x08;

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x07 + 0x08);
}

TEST_F(InstructionTests, AdditionNegativeFlagSet) {
    uint8_t b = -0x07;
    cpu->rega = 0x03;

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, static_cast<uint8_t>(0x03 - 0x07));
    ASSERT_TRUE(GET_N(cpu));
}

TEST_F(InstructionTests, AdditionNegativeFlagClear) {
    uint8_t b = 0x07;
    cpu->rega = -0x03;
    SET_N(cpu);

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, -0x03 + 0x07);
    ASSERT_FALSE(GET_N(cpu));
}

TEST_F(InstructionTests, AdditionZeroFlagSet) {
    uint8_t b = -0x07;
    cpu->rega = 0x07;

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0);
    ASSERT_TRUE(GET_Z(cpu));
}

TEST_F(InstructionTests, AdditionZeroFlagClear) {
    uint8_t b = 0x07;
    cpu->rega = 0;
    SET_Z(cpu);

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x07);
    ASSERT_FALSE(GET_Z(cpu));
}

TEST_F(InstructionTests, AdditionCarryInFlag) {
    uint8_t b = 1;
    cpu->rega = 1;
    SET_C(cpu);

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 3);
    ASSERT_FALSE(GET_C(cpu));
}

TEST_F(InstructionTests, AdditionCarryOutFlagSet) {
    uint8_t b = 1;
    cpu->rega = 0b11111111;

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0);
    ASSERT_TRUE(GET_C(cpu));
}

TEST_F(InstructionTests, AdditionCarryOutFlagClear) {
    uint8_t b = 1;
    cpu->rega = 1;
    SET_C(cpu);

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 3);
    ASSERT_FALSE(GET_C(cpu));
}

TEST_F(InstructionTests, AdditionOverflowFlag) {
    uint8_t b = 1;
    cpu->rega = 0b01111111;

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x80);
    ASSERT_TRUE(GET_V(cpu));
}

TEST_F(InstructionTests, AdditionBCDFlag) {
    uint8_t b = 0x27;
    cpu->rega = 0x34;
    SET_D(cpu);

    adc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x61);
}

TEST_F(InstructionTests, SubstractionSimple) {
    uint8_t b = 0x07;

    sbc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, static_cast<uint8_t>(-0x07));
}

TEST_F(InstructionTests, SubstractionNegativeFlagSet) {
    uint8_t b = 0x07;
    cpu->rega = 0x03;

    sbc(cpu, mem, &b);

    ASSERT_TRUE(GET_N(cpu));
}

TEST_F(InstructionTests, SubstractionNegativeFlagClear) {
    uint8_t b = -0x07;
    cpu->rega = -0x03;
    SET_N(cpu);

    sbc(cpu, mem, &b);

    ASSERT_FALSE(GET_N(cpu));
}

TEST_F(InstructionTests, SubstractionZeroFlagSet) {
    uint8_t b = 0x03;
    cpu->rega = 0x03;

    sbc(cpu, mem, &b);

    ASSERT_TRUE(GET_Z(cpu));
}

TEST_F(InstructionTests, SubstractionZeroFlagClear) {
    uint8_t b = 0x03;
    cpu->rega = 0x00;
    SET_Z(cpu);

    sbc(cpu, mem, &b);

    ASSERT_FALSE(GET_Z(cpu));
}

TEST_F(InstructionTests, SubstractionBorrowInFlag) {
    uint8_t b = 0x03;
    cpu->rega = 0x08;
    SET_C(cpu);

    sbc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x04);
    ASSERT_FALSE(GET_C(cpu));
}

TEST_F(InstructionTests, SubstractionBorrowOutFlagSet) {
    uint8_t b = 0x10;
    cpu->rega = 0x08;

    sbc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0xF8);
    ASSERT_TRUE(GET_C(cpu));
}

TEST_F(InstructionTests, SubstractionBorrowOutFlagClear) {
    uint8_t b = 0x03;
    cpu->rega = 0x08;
    SET_C(cpu);

    sbc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x04);
    ASSERT_FALSE(GET_C(cpu));
}

TEST_F(InstructionTests, SubstractionOverflowFlag) {
    uint8_t b = 1;
    cpu->rega = 0x80;

    sbc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x7F);
    ASSERT_TRUE(GET_V(cpu));
}

TEST_F(InstructionTests, SubstractionBCDTestFlagSet) {
    uint8_t b = 0x03;
    cpu->rega = 0x80;
    SET_D(cpu);

    sbc(cpu, mem, &b);

    ASSERT_EQ(cpu->rega, 0x77);
}
