cmake_minimum_required(VERSION 3.10)
project(V2RayLikeApp)

set(CMAKE_CXX_STANDARD 11)

find_package(Qt5Widgets REQUIRED)

add_executable(V2RayLike main.cpp Logger.cpp)
target_link_libraries(V2RayLike Qt5::Widgets)
