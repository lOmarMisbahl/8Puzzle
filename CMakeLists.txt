cmake_minimum_required(VERSION 3.16)
project(8PuzzleLocal)

set(CMAKE_CXX_STANDARD 14)

add_executable(8PuzzleLocal main.cpp Node.cpp Node.h BFS.cpp BFS.h)