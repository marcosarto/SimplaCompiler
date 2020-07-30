cmake_minimum_required(VERSION 3.16)
project(provaTecnologie)

set(CMAKE_C_STANDARD 99)

add_executable(provaTecnologie parser.h def.h table.h table.c parser.c lexer.c tree.c semantica.h semantica.c)