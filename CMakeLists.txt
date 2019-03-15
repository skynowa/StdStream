cmake_minimum_required(VERSION 3.10)

project(StdStream_Test)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wformat")

add_executable(StdStream_Test StdStream_Test.cpp)