cmake_minimum_required(VERSION 4.2)
project(ListSerialization LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


find_package(Boost REQUIRED serialization)

add_executable(convert main.cpp)
target_link_libraries(convert PRIVATE Boost::serialization)
