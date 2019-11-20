cmake_minimum_required(VERSION 3.5)

project(sem_test)


file(GLOB_RECURSE SEM_SOURCE main.cpp)
add_executable(sem_test ${SEM_SOURCE})
target_link_libraries(sem_test pthread)
