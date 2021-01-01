add_executable(ContainerBenchmarks 
               ./main.cpp 
               ./ExampleBenchmarks.cpp
               ./CommunicationData.cpp )

target_link_libraries(ContainerBenchmarks 
                      benchmark
                      pthread)
