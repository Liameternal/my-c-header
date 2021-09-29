cmake_minimum_required(VERSION 3.20)
project(myhead C)

set(CMAKE_C_STANDARD 11)

add_executable(myhead drive.c myself.c)
target_link_libraries(myhead m)
