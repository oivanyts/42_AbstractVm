cmake_minimum_required(VERSION 3.14)
project(abstractVm)

set(CMAKE_CXX_STANDARD 17)

add_executable(abstractVm
        src/main.cpp
        src/Creator.cpp inc/TOperant.h src/Parser.cpp inc/Parser.h src/Lexer.cpp inc/Lexer.h)
target_include_directories(abstractVm PRIVATE inc)
