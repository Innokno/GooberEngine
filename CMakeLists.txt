cmake_minimum_required(VERSION 3.10)
project(Raycaster)

find_package(SDL2 REQUIRED)

add_executable(Raycaster main.cpp)

target_include_directories(Raycaster PRIVATE /opt/homebrew/include/SDL2)
target_link_libraries(Raycaster PRIVATE SDL2)
