add_executable(ContainerBenchmarks 
               ./main.cpp 
               ./ExampleBenchmarks.cpp
               ./CodeToTest.cpp )

target_link_libraries(ContainerBenchmarks 
                      benchmark
                      pthread)