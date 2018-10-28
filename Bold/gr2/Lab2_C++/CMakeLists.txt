cmake_minimum_required(VERSION 3.0.0)
project(main.exe)

add_executable(main.exe 2.cpp tab.cpp tab.h)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}  -g -Wall -DDELETE")
set(CMAKE_CXX_FLAGS_RELESE "${CMAKE_CXX_FLAGS_RELESE} -Wall")

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
