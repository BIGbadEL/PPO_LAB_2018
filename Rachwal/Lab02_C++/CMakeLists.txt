cmake_minimum_required(VERSION 3.0.0)
project(main.exe)

file(GLOB_RECURSE src src/*.cpp)
file(GLOB_RECURSE inc include/*.h)

add_executable(main.exe main.cpp ${src} ${inc})

add_compile_options(-g -Wall -pedantic -DMAPCALC)

set(CMAKE_PROJECT_NAME ${PROJECT_NAME})