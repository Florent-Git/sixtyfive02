#include "test.h"

START_SF02_TEST(ADC_IMM) {
    execute_instruction(cpu, mem, inst, 0x69, 0x07, 0x00);
    ck_assert_int_eq(cpu->rega, 0x07);
}
END_SF02_TEST

START_SF02_TEST(ADC_ZERO) {
    mem->pages[0]->content[0x69] = 0xFD;
    execute_instruction(cpu, mem, inst, 0x65, 0x69, 0x00);
    ck_assert_int_eq(cpu->rega, 0xFD);
}
END_SF02_TEST

START_SF02_TEST(ADC_ZERO_X) {
    mem->pages[0]->content[0x6D] = 0xAB;
    cpu->regx = 0x04;
    execute_instruction(cpu, mem, inst, 0x75, 0x69, 0x00);
    ck_assert_int_eq(cpu->rega, 0xAB);
}
END_SF02_TEST

START_SF02_TEST(ADC_ABS) {
    mem->pages[0xAB]->content[0xCD] = 0xF1;
    execute_instruction(cpu, mem, inst, 0x6D, 0xCD, 0xAB);
    ck_assert_int_eq(cpu->rega, 0xF1);
}
END_SF02_TEST

START_SF02_TEST(ADC_ABS_X) {
    mem->pages[0xAB]->content[0xD1] = 0xDD;
    cpu->regx = 0x04;
    execute_instruction(cpu, mem, inst, 0x7D, 0xCD, 0xAB);
    ck_assert_int_eq(cpu->rega, 0xDD);
}
END_SF02_TEST

START_SF02_TEST(ADC_ABS_Y) {
    mem->pages[0xAB]->content[0xD2] = 0xEE;
    cpu->regy = 0x05;
    execute_instruction(cpu, mem, inst, 0x79, 0xCD, 0xAB);
    ck_assert_int_eq(cpu->rega, 0xEE);
}
END_SF02_TEST

START_SF02_TEST(ADC_IND_X) {
    mem->pages[0x00]->content[0x17] = 0x34;
    mem->pages[0x00]->content[0x18] = 0x56;
    mem->pages[0x56]->content[0x34] = 0x1C;
    cpu->regx = 0x05;
    execute_instruction(cpu, mem, inst, 0x61, 0x12, 0x00);
    ck_assert_int_eq(cpu->rega, 0x1C);
}
END_SF02_TEST

START_SF02_TEST(ADC_IND_Y) {
    mem->pages[0x00]->content[0x12] = 0x34;
    mem->pages[0x00]->content[0x13] = 0x56;
    mem->pages[0x56]->content[0x3A] = 0xC1;
    cpu->regy = 0x06;
    execute_instruction(cpu, mem, inst, 0x71, 0x12, 0x00);
    execute_instruction(cpu, mem, inst, 0x61, 0x12, 0x00);
    ck_assert_int_eq(cpu->rega, 0xC1);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_N) {
    execute_instruction(cpu, mem, inst, 0x69, -0x07, 0x00);
    ck_assert_int_eq(get_N(cpu), 1);
    ck_assert_int_eq(cpu->sr ^ N, 0);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_Z) {
    execute_instruction(cpu, mem, inst, 0x69, -0x07, 0x00);
    ck_assert_int_eq(get_Z(cpu), 1);
    ck_assert_int_eq(cpu->sr ^ N, 0);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_C) {
    execute_instruction(cpu, mem, inst, 0x69, -0x07, 0x00);
    ck_assert_int_eq(get_C(cpu), 1);
    ck_assert_int_eq(cpu->sr ^ N, 0);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_V) {
    execute_instruction(cpu, mem, inst, 0x69, -0x07, 0x00);
    ck_assert_int_eq(get_V(cpu), 1);
    ck_assert_int_eq(cpu->sr ^ N, 0);
}
END_SF02_TEST

Suite* arithmetic_suite(void) {
    Suite *s = suite_create("Arithmetic");

    TCase *adc_imm = tcase_create("ADC_IMM");
    tcase_add_test(adc_imm, ADC_IMM);
    suite_add_tcase(s, adc_imm);

    TCase *adc_zero = tcase_create("ADC_ZERO");
    tcase_add_test(adc_zero, ADC_ZERO);
    suite_add_tcase(s, adc_zero);

    TCase *adc_zero_x = tcase_create("ADC_ZERO_X");
    tcase_add_test(adc_zero_x, ADC_ZERO_X);
    suite_add_tcase(s, adc_zero_x);

    TCase *adc_abs = tcase_create("ADC_ABS");
    tcase_add_test(adc_abs, ADC_ABS);
    suite_add_tcase(s, adc_abs);

    TCase *adc_abs_x = tcase_create("ADC_ABS_X");
    tcase_add_test(adc_abs_x, ADC_ABS_X);
    suite_add_tcase(s, adc_abs_x);

    TCase *adc_abs_y = tcase_create("ADC_ABS_Y");
    tcase_add_test(adc_abs_y, ADC_ABS_Y);
    suite_add_tcase(s, adc_abs_y);

    TCase *adc_ind_x = tcase_create("ADC_IND_X");
    tcase_add_test(adc_ind_x, ADC_IND_X);
    suite_add_tcase(s, adc_ind_x);

    TCase *adc_ind_y = tcase_create("ADC_IND_Y");
    tcase_add_test(adc_ind_y, ADC_IND_Y);
    suite_add_tcase(s, adc_ind_y);

    return s;
}

int main() {
    Suite *s = arithmetic_suite();
    SRunner *sr = srunner_create(s);
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_VERBOSE);
    const int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
