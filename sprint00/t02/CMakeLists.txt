cmake_minimum_required(VERSION 3.1)

project(t02 LANGUAGES CXX)
set(SOURCE_EXE main.cpp walletManager.cpp)

add_compile_options(
        -Werror
        -Wall
        -Wextra
        -Wpedantic
)

if(NOT CMAKE_CXX_EXTENSIONS)
    set(CMAKE_CXX_EXTENSIONS OFF)
endif()

add_executable(getSomeSeptims ${SOURCE_EXE})