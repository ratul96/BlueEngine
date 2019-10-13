cmake_minimum_required(VERSION 2.6)
project(BlueEngine)

include_directories(src)

add_library(BlueEngine
src/source/Core.cpp
src/source/Core.h
src/source/Entity.h
src/source/PositionComponent.h
)


add_executable(sandbox
src/sandbox/main.cpp
)

target_link_libraries(sandbox BlueEngine)