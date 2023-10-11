cmake_minimum_required(VERSION 3.26)
project(calculator_lab1)

set(CMAKE_CXX_STANDARD 17)

set(PROJECT_HEADERS Calculator.h)
add_executable(calculator_lab1 ${PROJECT_SOURCE_DIR}/ main.cpp Calculator.cpp "Dll_Reader.cpp" "Dll_Reader.h")
