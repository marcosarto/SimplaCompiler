cmake_minimum_required(VERSION 3.16)
project(provaTecnologie)

set(CMAKE_C_STANDARD 99)

add_executable(provaTecnologie def.h heap.h heap.c interprete.h interprete.c lexer.c parser.h parser.c runStructure.c runStructure.h semantica.h semantica.c stringHeap.c stringHeap.h stringPoolStructure.c stringPoolStructure.h table.h table.c tree.c writeToFile.h writeToFile.c)