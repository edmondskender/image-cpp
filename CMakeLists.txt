cmake_minimum_required(VERSION 3.29)
project(Imageklasse)

set(CMAKE_CXX_STANDARD 20)

add_executable(Imageklasse main.cpp
        image.cpp
        image.h
        pixel.h
        pixel.cpp)
