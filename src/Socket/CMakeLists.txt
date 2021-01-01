add_library(SocketServer 
            ./SocketServer.cpp)

add_executable(SocketExample 
               ./main.cpp)

target_link_libraries(SocketExample 
                      SocketServer)