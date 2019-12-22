cmake_minimum_required(VERSION 3.15)
project(searchExp C)

set(CMAKE_C_STANDARD 99)

add_executable(searchExp main.c BinSearch.h BinSearchImpl.c)