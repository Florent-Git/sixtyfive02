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
        src/inst/flags.c
        src/inst/flags.h
)

target_include_directories(sixtyfive02-lib PUBLIC src)

add_executable(sixtyfive02
        src/main.c
)

target_link_libraries(sixtyfive02 PRIVATE sixtyfive02-lib)

# Setting up testing

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(sixtyfive02-test
    test/mem/mem_test.cpp
        test/cpu/cpu_test.cpp
        test/inst/inst_test.cpp
)

target_link_libraries(
    sixtyfive02-test
    sixtyfive02-lib
    GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(sixtyfive02-test)

file(COPY gdb DESTINATION ${CMAKE_BINARY_DIR})
