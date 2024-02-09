//
// Created by margaux on 24/02/02.
//

#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <../src/cpu/cpu.h>
#include <../src/mem/mem.h>
#include <../src/inst/instruction_table.h>


#define START_SF02_TEST(__testname)\
    START_TEST(__testname) {\
        struct cpu* cpu = initialize_cpu();\
        struct mem* mem = initialize_memory();

#define END_SF02_TEST\
    free_memory(mem);\
    free_cpu(cpu);\
    } END_TEST

#define END_SUITE(__suitename)\
    free(__suitename)

#endif //TEST_H
