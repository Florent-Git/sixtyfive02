cmake_minimum_required(VERSION 3.0)
project(sixtyfive02)

set(CMAKE_C_STANDARD 17)

add_executable(sixtyfive02 ./src/main.c ./src/cpu/cpu.c ./src/cpu/types.c ./src/cpu/cpu.h ./src/cpu/types.h ./src/mem/mem.h ./src/mem/mem.c ./src/inst/instruction_table.h src/inst/arith.c ./src/inst/instruction_table.c src/inst/arith.h
        src/inst/trans.c
        src/inst/trans.h
)