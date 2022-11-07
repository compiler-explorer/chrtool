cmake_minimum_required(VERSION 3.25)

project(cechrtool)

set(CMAKE_CXX_STANDARD 20)

add_compile_options(-Wall -Wextra -Wconversion)

add_executable(chrtool
    chrtool.cpp)
