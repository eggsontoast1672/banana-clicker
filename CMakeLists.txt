cmake_minimum_required(VERSION 3.0)

project(BananaClicker)

set(CMAKE_C_STANDARD 90)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(PkgConfig)

pkg_check_modules(SDL2 REQUIRED sdl2)

add_executable(clicker src/main.c)

target_compile_options(clicker PRIVATE -Wall -Werror -Wextra -Wpedantic)
target_link_libraries(clicker PRIVATE ${SDL2_LIBRARIES})
