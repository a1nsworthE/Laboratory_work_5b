cmake_minimum_required(VERSION 3.21)
project(Laboratory_5b C)

set(CMAKE_C_STANDARD 23)

add_executable(Laboratory_5b main.c)
add_executable(T test.c)
add_executable(Tasks function_for_tasks.c)

add_subdirectory(includes)

target_link_libraries(Laboratory_5b structs)
target_link_libraries(Laboratory_5b algorithms)
target_link_libraries(T structs)
target_link_libraries(T algorithms)
target_link_libraries(Tasks structs)
target_link_libraries(Tasks algorithms)


