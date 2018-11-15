cmake_minimum_required(VERSION 3.0)
project(main.exe)

file(GLOB src ${PROJECT_SOURCE_DIR}/src/*.cpp)
file(GLOB headers ${PROJECT_SOURCE_DIR}/include/*.h)
file(GLOB main ${PROJECT_SOURCE_DIR}/*.cpp)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main.exe ${main} ${headers} ${src})
add_compile_options(-g -Wall -pedantic)

set(CMAKE_PROJECT_NAME ${PROJECT_NAME})