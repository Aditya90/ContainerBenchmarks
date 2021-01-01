cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_COMPILER g++-10)
set(CMAKE_C_COMPILER gcc-10)

project(ContainerBenchmarks)

add_compile_options(-std=c++20)

# add_compile_options(/std:c++latest)

# Specify directory for bins and libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Disable the gtests for google benchmark as we dont have a gtest dependency added yet
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)
set(BENCHMARK_FORMAT json)

# Specify include directories
include_directories(include docker)

# Add source sub directory
add_subdirectory(benchmark)
add_subdirectory(src)
