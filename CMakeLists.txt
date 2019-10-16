cmake_minimum_required(VERSION 2.6)
project(BlueEngine)

include_directories(src)

add_library(BlueEngine
src/source/Core.h
src/source/Entity.h
src/source/PositionComponent.h
src/source/Mesh.h
src/source/Model.h
src/source/Material.h
src/source/Core.cpp
src/source/Entity.cpp
src/source/PositionComponent.cpp
src/source/Mesh.cpp
src/source/Model.cpp
src/source/Material.cpp
)


add_executable(sandbox
src/sandbox/main.cpp
)

target_link_libraries(sandbox BlueEngine)