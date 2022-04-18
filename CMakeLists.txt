cmake_minimum_required(VERSION 3.22.4)

set(PROJECT_NAME hsechain)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME} src/main.cc src/obj.cc)
target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include)
target_link_libraries(${PROJECT_NAME} /usr/local/lib/librpc.a)
