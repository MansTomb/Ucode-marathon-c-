cmake_minimum_required(VERSION 3.1)

project(t03 LANGUAGES CXX)
set(SOURCE_EXE main.cpp src/rabbits.cpp)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(vampireRabbits ${SOURCE_EXE})
