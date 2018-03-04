cmake_minimum_required(VERSION 3.9)
project(task1)

set(CMAKE_CXX_STANDARD 11)

add_executable(task1 main.cpp)
set(CMAKE_CXX_COMPILER /usr/local/bin/g++-7)
set(CMAKE_C_COMPILER /usr/local/bin/gcc-7)
# enable openmp using -fopenmp
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -fopenmp")