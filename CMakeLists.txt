cmake_minimum_required(VERSION 3.21)
project(huffmanZip)

set(CMAKE_CXX_STANDARD 11)

add_executable(huffmanZip main.cpp huffmanTree.cpp huffmanTree.h compress.cpp compress.h processBar.cpp processBar.h)
