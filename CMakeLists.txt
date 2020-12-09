cmake_minimum_required(VERSION 3.14)
project(ContainerBenchmarks)

add_compile_options(-std=c++17)

# Specify directory for bins and libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Disable the gtests for google benchmark as we dont have a gtest dependency added yet
set(BENCHMARK_ENABLE_GTEST_TESTS OFF)

# Specify include directories
include_directories(include docker)

# Add source sub directory
add_subdirectory(benchmark)
add_subdirectory(src)
