cmake_minimum_required(VERSION 3.0.0)
project(main.exe)

file(GLOB_RECURSE src *.cpp)
file(GLOB_RECURSE includ *.h)

#add_executable(main.exe ${src} ${includ})
add_executable(main.exe 3.cpp bitarr.cpp ${includ})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})