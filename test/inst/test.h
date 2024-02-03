//
// Created by margaux on 24/02/02.
//

#ifndef TEST_H
#define TEST_H

#include <check.h>
#include <cpu/cpu.h>
#include <mem/mem.h>
#include <inst/instruction_table.h>

#define START_SF02_TEST(__testname)\
    START_TEST(__testname) {\
        struct cpu* cpu = initialize_cpu();\
        struct mem* mem = initialize_memory();\
        struct inst* inst = initialize_inst_table();

#define END_SF02_TEST\
    free_inst_table(inst);\
    free_memory(mem);\
    free_cpu(cpu);\
    } END_TEST

#endif //TEST_H
