cmake_minimum_required( VERSION 2.8 )
 
project (main.exe)
file(GLOB source ${PROJECT_SOURCE_DIR}/src/*.cpp)
include_directories(${PROJECT_SOURCE_DIR}/include)
 
add_executable(main.exe main.cpp ${source})
 
add_compile_options(-g -Wall -pedantic -DMAPCALC)
 
set(CMAKE_PROJECT_NAME ${PROJECT_NAME})
