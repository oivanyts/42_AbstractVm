cmake_minimum_required(VERSION 3.14)
project(abstractVm)

set(CMAKE_CXX_STANDARD 17)

add_executable(abstractVm
        src/main.cpp
        src/Creator.cpp src/Int8.cpp inc/Int8.h src/Int16.cpp inc/Int16.h src/Int32.cpp inc/Int32.h src/Float.cpp inc/Float.h src/Double.cpp inc/Double.h)
target_include_directories(abstractVm PRIVATE inc)
