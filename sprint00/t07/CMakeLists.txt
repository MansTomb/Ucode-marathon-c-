cmake_minimum_required(VERSION 3.1)

project(t07 LANGUAGES CXX)
set(SOURCE_EXE main.cpp src/commands.cpp)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
)

add_executable(inventory ${SOURCE_EXE})