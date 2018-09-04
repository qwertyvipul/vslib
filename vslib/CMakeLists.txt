cmake_minimum_required(VERSION 3.12)
project(vslib)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(vslib
        data_structures.cpp
        data_structures.h
        main.cpp
        singly_linked_list.cpp
        singly_linked_list.h
        vslib.cpp
        vslib.h)
