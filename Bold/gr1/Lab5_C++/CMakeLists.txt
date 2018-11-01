cmake_minimum_required(VERSION 3.0.0)
project(main.exe)


file(GLOB source *.cpp)
file(GLOB include *.h)

add_executable(main.exe ${source} ${include})

add_compile_options( -Wall -g )

set(CMAKE_pROJECT_NAME ${PROJECT_NAME})
