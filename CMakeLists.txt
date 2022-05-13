cmake_minimum_required(VERSION 3.16)

project(client)

#set(CMAKE_CXX_STANDARD 11)
# 设置指定的C++编译器版本是必须的，如果不设置，或者为OFF，则指定版本不可用时，会使用上一版本。
set(CMAKE_CXX_STANDARD_REQUIRED ON)
# # 指定为C++14 版本
# set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(D:\\boost_cpp_libaray\\boost_1_77_0)
link_directories(D:\\boost_cpp_libaray\\boost_1_77_0\\libs)


link_libraries(ws2_32)
link_libraries(wsock32)

add_executable(client client.cpp)
