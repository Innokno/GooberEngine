cmake_minimum_required(VERSION 3.10)
project(Raycaster)

find_package(SDL2 REQUIRED)

add_executable(MyGame.out main.cpp)

target_include_directories(MyGame.out PRIVATE /opt/homebrew/include/SDL2)
target_link_libraries(MyGame.out PRIVATE SDL2)
