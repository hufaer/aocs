cmake_minimum_required(VERSION 3.16)
project(hw2_avs)

set(CMAKE_CXX_STANDARD 14)

add_executable(hw2_avs main.cpp container.cpp parallelepiped.cpp sphere.cpp shape.cpp tetrahedron.cpp container.h parallelepiped.h tetrahedron.h sphere.h random.h shape.h)
