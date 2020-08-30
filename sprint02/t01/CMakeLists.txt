cmake_minimum_required(VERSION 3.1)

project(t01 LANGUAGES CXX)
set(SOURCE_EXE main.cpp)
set(CMAKE_CXX_EXTENSIONS OFF)
add_subdirectory(src)

add_compile_options(
        -std=c++17
        -Werror
        -Wall
        -Wextra
        -Wpedantic
        -Wno-unused-parameter
)

add_executable(countUniqueWords ${SOURCE_EXE})
