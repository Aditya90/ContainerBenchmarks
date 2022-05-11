cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_COMPILER g++-10)
set(CMAKE_C_COMPILER gcc-10)

project(ContainerBenchmarks)

add_compile_options(-std=c++20)


include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

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
