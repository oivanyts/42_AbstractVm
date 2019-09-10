cmake_minimum_required(VERSION 3.14)
project(abstractVm)

set(CMAKE_CXX_STANDARD 17)

add_executable(abstractVm
        src/main.cpp
        src/Creator.cpp
        src/Parser.cpp
        src/Lexer.cpp
        src/Token.cpp src/Command.cpp inc/Command.h src/Machine.cpp inc/Machine.h)

target_include_directories(abstractVm PRIVATE inc)
