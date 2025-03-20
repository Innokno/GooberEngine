cmake_minimum_required(VERSION 3.10)
project(Raycaster)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g")
set(CMAKE_EXPORT_COMPILE_COMMANDS true)

find_package(SDL2 REQUIRED)
link_directories(./yaml-cpp)

add_executable(MyGame.out "")
include(sourcelist.cmake)

add_subdirectory(./yaml-cpp)

target_include_directories(MyGame.out PRIVATE ${CMAKE_SOURCE_DIR}/include)
target_include_directories(MyGame.out PRIVATE /opt/homebrew/include/SDL2)
target_link_libraries(MyGame.out PRIVATE SDL2)
target_link_libraries(MyGame.out PRIVATE yaml-cpp)
