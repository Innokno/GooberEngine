cmake_minimum_required(VERSION 3.10)
project(Raycaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

find_package(SDL2 REQUIRED)
add_subdirectory(./yaml-cpp/ EXCLUDE_FROM_ALL)

add_executable(MyGame.out "")

include(sourcelist.cmake)

target_include_directories(MyGame.out PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_link_libraries(MyGame.out PRIVATE yaml-cpp)
target_link_libraries(MyGame.out PRIVATE SDL2)
