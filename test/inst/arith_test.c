#include "arith_test.h"


START_SF02_TEST(ADC_IMM) {
    byte b = 0x07;
    adc(cpu, mem, &b);
    ck_assert_int_eq(cpu->rega, 0x07);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_N) {
    byte b = -0x07;
    adc(cpu, mem, &b);
    ck_assert_int_eq(get_N(cpu), 1);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_Z) {
    cpu->rega = -0x08;
    byte b = 0x08;
    adc(cpu, mem, &b);
    ck_assert_int_eq(get_Z(cpu), 1);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_C) {
    cpu->rega = 1;
    byte b = 0b11111111;
    adc(cpu, mem, &b);
    ck_assert_int_eq(get_C(cpu), 1);
}
END_SF02_TEST

START_SF02_TEST(ADC_IMM_FLAG_V) {
    cpu->rega = 0b01111111;
    byte b = 1;
    adc(cpu, mem, &b);
    ck_assert_int_eq(get_V(cpu), 1);
}
END_SF02_TEST

START_SF02_TEST(SBC_IMM) {
    byte b = 0x07;
    sbc(cpu, mem, &b);
    ck_assert_int_eq(cpu->rega, (byte) -0x07);
}
END_SF02_TEST

Suite* arithmetic_suite(void) {
    Suite *s = suite_create("Arithmetic");

    TCase *adc = tcase_create("ADC");
    tcase_add_test(adc, ADC_IMM);
    tcase_add_test(adc, ADC_IMM_FLAG_N);
    tcase_add_test(adc, ADC_IMM_FLAG_Z);
    tcase_add_test(adc, ADC_IMM_FLAG_C);
    tcase_add_test(adc, ADC_IMM_FLAG_V);
    suite_add_tcase(s, adc);

    TCase *sbc = tcase_create("SBC");
    tcase_add_test(sbc, SBC_IMM);
    // tcase_add_test(sbc, SBC_IMM_FLAG_N);
    // tcase_add_test(sbc, SBC_IMM_FLAG_Z);
    // tcase_add_test(sbc, SBC_IMM_FLAG_C);
    // tcase_add_test(sbc, SBC_IMM_FLAG_V);
    suite_add_tcase(s, sbc);

    return s;
}


