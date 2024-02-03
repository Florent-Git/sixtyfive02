cmake_minimum_required(VERSION 3.22)
project(sixtyfive02)

list(APPEND CMAKE_MODULE_PATH /usr/share/doc/check/examples/cmake)
list(APPEND CMAKE_C_FLAGS -g)

set(CMAKE_C_STANDARD 17)

add_library(sixtyfive02-lib
        src/cpu/cpu.c
        src/cpu/types.c
        src/mem/mem.c
        src/inst/arith.c
        src/inst/instruction_table.c
        src/inst/trans.c
)

target_include_directories(sixtyfive02-lib PUBLIC src)

add_executable(sixtyfive02
        src/main.c
)

target_link_libraries(sixtyfive02 PRIVATE sixtyfive02-lib)

find_package(Check)

add_executable(sixtyfive02-test
        test/inst/arith_test.c
        test/inst/test.h
)

target_link_libraries(sixtyfive02-test PRIVATE check sixtyfive02-lib m subunit)

