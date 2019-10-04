cmake_minimum_required(VERSION 2.6)
project(BlueEngine)

add_library(BlueEngine
src/source/Core.cpp
)

add_executable(sandbox
src/sandbox/main.cpp
)

target_link_libraries(sandbox BlueEngine)