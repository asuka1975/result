cmake_minimum_required(VERSION 3.20)

project(result)

set(CMAKE_CXX_STANDARD 20)

add_library(result src/result/result.cpp)

target_include_directories(result PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

