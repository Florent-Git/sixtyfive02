#include "inst/arith_test.h"
#include "mem/mem_test.h"

int main() {
    Suite *arith = arithmetic_suite();
    Suite *mem = mem_suite();

    SRunner *sr = srunner_create(arith);
    srunner_add_suite(sr, mem);
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_VERBOSE);
    const int number_failed = srunner_ntests_failed(sr);
    srunner_free(sr);
    return number_failed == 0 ? EXIT_SUCCESS : EXIT_FAILURE;
}
