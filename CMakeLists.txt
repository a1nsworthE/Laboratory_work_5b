cmake_minimum_required(VERSION 3.21)
project(laba5b C)

set(CMAKE_C_STANDARD 23)

add_executable(laba5b main.c)
add_executable(T test.c)

add_subdirectory(includes)

target_link_libraries(laba5b structs)
target_link_libraries(laba5b algorithms)
target_link_libraries(T structs)
target_link_libraries(T algorithms)

