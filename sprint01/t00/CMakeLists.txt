cmake_minimum_required(VERSION 3.1)

project(t00 LANGUAGES CXX)
set(SOURCE_EXE main.cpp)
set(CMAKE_CXX_EXTENSIONS OFF)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
)

add_executable(simpleSort ${SOURCE_EXE})
q
