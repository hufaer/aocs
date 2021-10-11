cmake_minimum_required(VERSION 3.16)
project(hw1_avs)

set(CMAKE_CXX_STANDARD 20)

add_executable(hw1_avs container.h parallelepiped.h random.h shape.h sphere.h tetrahedron.h main.cpp container.cpp shape.cpp parallelepiped.cpp tetrahedron.cpp sphere.cpp)
