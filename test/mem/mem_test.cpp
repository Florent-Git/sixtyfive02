#include <gtest/gtest.h>

extern "C" {
#include <mem/mem.h>
#include <cpu/cpu.h>
}

class MemoryTest : public testing::Test {
protected:
    MemoryTest() {
        this->cpu = initialize_cpu();
        this->mem = initialize_memory();
    }

    struct cpu *cpu;
    struct mem *mem;
};

TEST_F(MemoryTest, ImmediateMemory) {
    const uint8_t *addr = immediate(cpu, mem, 0x07, 0x00);

    ASSERT_EQ(addr, &cpu->tmp);
}

TEST_F(MemoryTest, AbsoluteMemory) {
    const uint8_t *addr = abs_addr(cpu, mem, 0x01, 0x23);

    ASSERT_EQ(addr, mem->pages[0x23]->content + 0x01);
}

TEST_F(MemoryTest, AbsoluteXMemory) {
    cpu->regx = 0xBA;
    const uint8_t *addr = abs_x(cpu, mem, 0x01, 0x23);

    ASSERT_EQ(addr, mem->pages[0x23]->content + 0x01 + 0xBA);
}

TEST_F(MemoryTest, AbsoluteYMemory) {
    cpu->regy = 0xAB;
    const uint8_t *addr = abs_y(cpu, mem, 0x01, 0x23);

    ASSERT_EQ(addr, mem->pages[0x23]->content + 0x01 + 0xAB);
}

TEST_F(MemoryTest, ZeroPageMemory) {
    const uint8_t *addr = zero_page(cpu, mem, 0x23, 0x00);

    ASSERT_EQ(addr, mem->pages[0x00]->content + 0x23);
}

TEST_F(MemoryTest, ZeroPageX) {
    cpu->regx = 0x11;
    const uint8_t *addr = zero_page_x(cpu, mem, 0x23, 0x00);

    ASSERT_EQ(addr, mem->pages[0x00]->content + 0x23 + 0x11);
}

TEST_F(MemoryTest, ZeroPageY) {
    cpu->regy = 0x22;
    const uint8_t *addr = zero_page_y(cpu, mem, 0x23, 0x00);

    ASSERT_EQ(addr, mem->pages[0x00]->content + 0x23 + 0x22);
}

TEST_F(MemoryTest, Indirect) {
    mem->pages[0xAB]->content[0xCD] = 0x12;
    mem->pages[0xAB]->content[0xCE] = 0x13;

    const uint8_t *addr = indirect(cpu, mem, 0xCD, 0xAB);

    ASSERT_EQ(addr, mem->pages[0x13]->content + 0x12);
}

TEST_F(MemoryTest, PreIndirect) {
    cpu->regx = 0x05;

    mem->pages[0x00]->content[0xCD + 0x05] = 0x12;
    mem->pages[0x00]->content[0xCE + 0x05] = 0x13;

    const uint8_t *addr = pre_indirect(cpu, mem, 0xCD, 0x00);

    ASSERT_EQ(addr, mem->pages[0x13]->content + 0x12);
}

TEST_F(MemoryTest, PostIndirect) {
    cpu->regy = 0x05;

    mem->pages[0x00]->content[0xCD] = 0x12;
    mem->pages[0x00]->content[0xCE] = 0x13;

    const uint8_t *addr = post_indirect(cpu, mem, 0xCD, 0x00);

    ASSERT_EQ(addr, mem->pages[0x13]->content + 0x12 + 0x05);
}
