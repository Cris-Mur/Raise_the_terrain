cmake_minimum_required(VERSION 3.16)
project(Raise_the_terrain C)

set(CMAKE_C_STANDARD 90)

find_package(SDL2 REQUIRED COMPONENTS SDL2::SDL2)
include_directories(${SDL2_INCLUDE_DIR})

add_executable(Raise_the_terrain Source/main.c Source/_Sdl_born.c Headers/basic_libs.h Source/_close_win.c Source/_init_map.c Source/_draw_map.c)
target_link_libraries(Raise_the_terrain SDL2::SDL2 ${SDL2_LIBRARY})
