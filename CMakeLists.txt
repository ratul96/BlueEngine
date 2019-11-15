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
src/source/MeshComponent.cpp
src/source/PositionComponent.cpp
src/source/Entity.cpp
src/source/MaterialComponent.h
src/source/MaterialComponent.cpp
src/source/Camera.h
src/source/Camera.cpp
src/source/blueengine.h
)

if(MSVC)
  target_link_libraries(BlueEngine glew32 SDL2 OpenGL32)
else()
  target_link_libraries(BlueEngine SDL2 GLEW GL)
endif()


add_executable(sandbox
src/sandbox/main.cpp
src/sandbox/TriangleRenderer.h
src/sandbox/TriangleRenderer.cpp
)

target_link_libraries(sandbox BlueEngine)
