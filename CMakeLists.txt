cmake_minimum_required(VERSION 3.26)
project(BasicsOfProgramming C)

set(CMAKE_C_STANDARD 11)

add_executable(BasicsOfProgramming
        main.c
        data_structures/vector/vector.c
        data_structures/vector/vector.h
        data_structures/vector/vectorVoid.c
        data_structures/vector/vectorVoid.h
)
