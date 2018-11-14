cmake_minimum_required(VERSION 3.12)

project(TP-Prog3)



set(CMAKE_CXX_STANDARD 11)


//directorio
include_directories(/usr/local/include/StanfordCPPLib/)



add_executable(TP6_3 TP6_3.cpp)

target_link_libraries(TP6_3 /usr/local/lib/libStanfordCPPLib.a)
