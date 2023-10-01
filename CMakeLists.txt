cmake_minimum_required(VERSION 3.26)
project(calculator_lab1)

set(CMAKE_CXX_STANDARD 20)

set(PROJECT_HEADERS Calculator.h)
add_executable(calculator_lab1 ${PROJECT_SOURCE_DIR}/ main.cpp Calculator.cpp "Dll_Reader.cpp" "Dll_Reader.h")

add_library(sin SHARED ./plugins/sin.cpp "plugins/sin.cpp" "Dll_Reader.cpp" "Dll_Reader.h")
add_library(cos SHARED ./plugins/cos.cpp "plugins/cos.cpp" "Dll_Reader.cpp" "Dll_Reader.h")
add_library(tg SHARED ./plugins/tg.cpp "plugins/tg.cpp" "Dll_Reader.cpp" "Dll_Reader.h")
add_library(ctg SHARED ./plugins/ctg.cpp "plugins/ctg.cpp" "Dll_Reader.cpp" "Dll_Reader.h")
add_library(ln SHARED ./plugins/ln.cpp "plugins/ln.cpp" "Dll_Reader.cpp" "Dll_Reader.h")
add_library(lg SHARED ./plugins/lg.cpp "plugins/lg.cpp" "Dll_Reader.cpp" "Dll_Reader.h")
add_library(sqrt SHARED ./plugins/sqrt.cpp "plugins/sqrt.cpp" "Dll_Reader.cpp" "Dll_Reader.h")

target_link_libraries(calculator_lab1 sin cos tg ctg ln lg sqrt)