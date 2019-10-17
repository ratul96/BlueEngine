cmake_minimum_required(VERSION 2.6)
project(BlueEngine)

include_directories(src)

add_library(BlueEngine
src/source/Core.h
src/source/Component.h
src/source/Component.cpp
src/source/Entity.h
src/source/PositionComponent.h
src/source/Core.cpp
src/source/MeshComponent.h
src/source.MeshComponent.cpp
src/source/PositionComponent.cpp
src/source/Entity.cpp
src/source/MaterialComponent.h
src/source/MaterialComponent.cpp
)


add_executable(sandbox
src/sandbox/main.cpp
)

target_link_libraries(sandbox BlueEngine)