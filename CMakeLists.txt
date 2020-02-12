cmake_minimum_required(VERSION 3.14)
project(ContainerBenchmarks)

# Specify directory for bins and libs
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Specify include directories
include_directories(include)

# Add source sub directory
add_subdirectory(src)
