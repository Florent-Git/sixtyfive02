//
// Created by margaux on 24/02/07.
//

#include "mem_test.h"

START_SF02_TEST(IMMEDATE_MEM) {
    const byte *addr = immediate(cpu, mem, 0x07, 0x00);
    ck_assert_ptr_eq(addr, &cpu->tmp);
}
END_SF02_TEST;

START_SF02_TEST(ABSOLUTE_MEM) {
    const byte *addr = abs_addr(cpu, mem, 0x01, 0x23);
    ck_assert_ptr_eq(addr, mem->pages[0x23]->content + 0x01);
} END_SF02_TEST;

START_SF02_TEST(ABSOLUTE_X_MEM) {
    cpu->regx = 0xBA;
    const byte *addr = abs_x(cpu, mem, 0x01, 0x23);
    ck_assert_ptr_eq(addr, mem->pages[0x23]->content + 0x01 + 0xBA);
} END_SF02_TEST;

START_SF02_TEST(ABSOLUTE_Y_MEM) {
    cpu->regy = 0xAB;
    const byte *addr = abs_y(cpu, mem, 0x01, 0x23);
    ck_assert_ptr_eq(addr, mem->pages[0x23]->content + 0x01 + 0xAB);
} END_SF02_TEST;

START_SF02_TEST(ZERO_PAGE_MEM) {
    const byte *addr = zero_page(cpu, mem, 0x23, 0x00);
    ck_assert_ptr_eq(addr, mem->pages[0x00]->content + 0x23);
} END_SF02_TEST;

START_SF02_TEST(ZERO_PAGE_X) {
    cpu->regx = 0x11;
    const byte *addr = zero_page_x(cpu, mem, 0x23, 0x00);
    ck_assert_ptr_eq(addr, mem->pages[0x00]->content + 0x23 + 0x11);
} END_SF02_TEST;

START_SF02_TEST(ZERO_PAGE_Y) {
    cpu->regy = 0x22;
    const byte *addr = zero_page_y(cpu, mem, 0x23, 0x00);
    ck_assert_ptr_eq(addr, mem->pages[0x00]->content + 0x23 + 0x22);
} END_SF02_TEST;

START_SF02_TEST(INDIRECT) {
    mem->pages[0xAB]->content[0xCD] = 0x12;
    mem->pages[0xAB]->content[0xCE] = 0x13;

    const byte *addr = indirect(cpu, mem, 0xCD, 0xAB);

    ck_assert_ptr_eq(addr, mem->pages[0x13]->content + 0x12);
} END_SF02_TEST;

START_SF02_TEST(PRE_INDIRECT) {
    cpu->regx = 0x05;

    mem->pages[0]->content[0xCD + 0x05] = 0x12;
    mem->pages[0]->content[0xCE + 0x05] = 0x13;

    const byte *addr = pre_indirect(cpu, mem, 0xCD, 0x00);

    ck_assert_ptr_eq(addr, mem->pages[0x13]->content + 0x12);
} END_SF02_TEST;

START_SF02_TEST(POST_INDIRECT) {
    cpu->regy = 0x05;

    mem->pages[0]->content[0xCD] = 0x12;
    mem->pages[0]->content[0xCE] = 0x13;

    const byte *addr = post_indirect(cpu, mem, 0xCD, 0x00);

    ck_assert_ptr_eq(addr, mem->pages[0x13]->content + 0x12 + 0x05);
} END_SF02_TEST;

Suite* mem_suite(void) {
    Suite *s = suite_create("Memory");

    TCase *adc = tcase_create("Memory");
    tcase_add_test(adc, IMMEDATE_MEM);
    tcase_add_test(adc, ZERO_PAGE_MEM);
    tcase_add_test(adc, ZERO_PAGE_X);
    tcase_add_test(adc, ZERO_PAGE_Y);
    tcase_add_test(adc, ABSOLUTE_MEM);
    tcase_add_test(adc, ABSOLUTE_X_MEM);
    tcase_add_test(adc, ABSOLUTE_Y_MEM);
    tcase_add_test(adc, INDIRECT);
    tcase_add_test(adc, PRE_INDIRECT);
    tcase_add_test(adc, POST_INDIRECT);
    suite_add_tcase(s, adc);

    return s;
}
