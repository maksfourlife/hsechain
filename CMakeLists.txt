cmake_minimum_required(VERSION 3.22.4)

set(PROJECT_NAME hsechain)
set(CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/main.cc
    src/BlockForks.cc
    src/Node.cc
    src/RpcService.cc
    src/RpcClient.cc
    src/Account.cc
    src/Block.cc)

target_include_directories(${PROJECT_NAME} PUBLIC /usr/local/include)
target_link_libraries(${PROJECT_NAME} /usr/local/lib/librpc.a)
target_link_libraries(${PROJECT_NAME} /usr/local/lib/libleveldb.a)
