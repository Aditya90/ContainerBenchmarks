add_executable(ContainerBenchmarks 
               ./main.cpp 
               ./ExampleBenchmarks.cpp)

target_link_libraries(ContainerBenchmarks 
                      benchmark
                      pthread)

add_subdirectory(DataStructures)