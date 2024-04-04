cmake_minimum_required(VERSION 3.26)
project(Basic_Containers)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Basic_Containers
        queue.cpp
        queue.h
        stack.cpp
        stack.h)
