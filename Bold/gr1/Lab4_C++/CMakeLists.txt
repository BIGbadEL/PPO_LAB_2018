cmake_minimum_required(VERSION 3.0.0)
project(btest VERSION 0.1.0)

add_executable(btest 4.cpp bitarray.cpp bitarray.h)
include(CTest)
enable_testing()

include(CPack)
