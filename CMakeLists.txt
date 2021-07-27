cmake_minimum_required(VERSION 2.8)

project(GOL)

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})


set(CMAKE_BUILD_TYPE Default)
set(CMAKE_C_FLAGS "-std=c99 -fdump-rtl-expand")

add_executable(GOL main.c graphics.c logic.c)
target_link_libraries(GOL ${SDL2_LIBRARIES})