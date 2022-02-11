cmake_minimum_required(VERSION 2.8)
project(Reflection)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS}  -Wall  -O3 -march=native ")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall   -O3 -march=native")

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(
${PROJECT_SOURCE_DIR}
${PROJECT_SOURCE_DIR}/include
)

add_library(${PROJECT_NAME} SHARED
src/head.cpp
)

target_link_libraries(${PROJECT_NAME})

add_executable(main main.cpp)
target_link_libraries(main ${PROJECT_NAME})