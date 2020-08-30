cmake_minimum_required(VERSION 3.1)

project(t02 LANGUAGES CXX)
set(SOURCE_EXE main.cpp src/towns.cpp)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(visitAll ${SOURCE_EXE})
