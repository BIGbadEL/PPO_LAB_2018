cmake_minimum_required(VERSION 3.0.0)
project(main.exe VERSION 0.1.0)

file(GLOB_RECURSE sources src/*.cpp)
file(GLOB_RECURSE headers include/*.h)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main.exe Main.cpp ${sources} ${headers})

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -g -Wall -DDELETE")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -Wall -DDELETE")


set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})

