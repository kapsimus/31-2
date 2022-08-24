cmake_minimum_required(VERSION 3.22)
project(31_2)

set(CMAKE_CXX_STANDARD 20)

add_executable(31_2 src/main.cpp include/IGraph.h src/IGraph.cpp include/ListGraph.h include/MatrixGraph.h src/ListGraph.cpp src/MatrixGraph.cpp)
target_include_directories(31_2 PUBLIC include)