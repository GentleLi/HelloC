cmake_minimum_required(VERSION 3.17)
project(HelloC C)

set(CMAKE_C_STANDARD 99)

add_executable(HelloC main.c hashtable.c reader.c input_from_console.c size_of.c insert_sort.h insert_sort.c sort.c sort.h print_util.c print_util.h)