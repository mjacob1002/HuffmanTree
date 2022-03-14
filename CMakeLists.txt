cmake_minimum_required(VERSION 3.14)
project(Huffman_Trees)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/build/bin)

add_executable(test_priority src/test_priority.cpp)
target_include_directories(test_priority PRIVATE include/)

add_executable(huffman_tree src/huffman.cpp src/main.cpp)
target_include_directories(huffman_tree PRIVATE include/)
