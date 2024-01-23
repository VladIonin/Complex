cmake_minimum_required(VERSION 3.24)
project(ComplexNumbers)

set(CMAKE_CXX_STANDARD 17)

add_library(Complex INTERFACE)
target_include_directories(Complex INTERFACE src)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(googletest-1.14.0)

set_target_properties(ComplexNumbers PROPERTIES LINKER_LANGUAGE CXX)
set_target_properties(ComplexNumbers_lib PROPERTIES LINKER_LANGUAGE CXX)