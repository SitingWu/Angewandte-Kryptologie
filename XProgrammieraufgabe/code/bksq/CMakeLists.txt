#bksq
cmake_minimum_required(VERSION 3.16)
project(bksq)

set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake)
set(bksq_src ${PROJECT_SOURCE_DIR}/bksq.c)
add_library(bksq_src ${bksq_src})

add_executable(bksq main.c)
target_link_libraries(bksq bksq_src)


#include_directories(${PROJECT_SOURCE_DIR}/util/include)



