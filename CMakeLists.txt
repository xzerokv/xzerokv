cmake_minimum_required(VERSION 3.16)

project(xzerokv C)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_compile_definitions(__FILE_PREFIX__="${CMAKE_CURRENT_SOURCE_DIR}")

add_executable(
    xzerokv
    src/main.c
    src/xzkv_sys.c
    src/xzkv_log.c
)
