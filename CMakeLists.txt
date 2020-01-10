cmake_minimum_required(VERSION 2.6)
project(BlueEngine)

include_directories(src)

add_library(rend
src/rend/Buffer.h
src/rend/Buffer.cpp
src/rend/Context.h
src/rend/Context.cpp
src/rend/Exception.h
src/rend/Exception.cpp
src/rend/mathutil.h
src/rend/Mesh.cpp
src/rend/Mesh.h
src/rend/rend.h
src/rend/RenderTexture.h
src/rend/RenderTexture.cpp
src/rend/Shader.h
src/rend/Shader.cpp
src/rend/Texture.h
src/rend/Texture.cpp
src/rend/TextureAdapter.h
src/rend/Util.h
src/rend/Util.cpp
)

if(MSVC)
  target_link_libraries(rend glew32 SDL2 OpenGL32 OpenAL32)
else()
  target_link_libraries(rend SDL2 GLEW GL openal)
endif()

add_library(BlueEngine
src/source/Core.h
src/source/Screen.h
src/source/Keyboard.h
src/source/Keyboard.cpp
src/source/BoxCollider.h
src/source/BoxCollider.cpp
src/source/Screen.cpp
src/source/Gui.h
src/source/Gui.cpp
src/source/NewSound.h
src/source/NewSound.cpp
src/source/Component.h
src/source/Component.cpp
src/source/Entity.h
src/source/Core.cpp
src/source/Lighting.h
src/source/Lighting.cpp
src/source/Mesh.h
src/source/Mesh.cpp
src/source/Entity.cpp
src/source/Material.h
src/source/Material.cpp
src/source/Resource.h
src/source/Resources.h
src/source/Renderer.h
src/source/Shaders.h
src/source/Shaders.cpp
src/source/Renderer.cpp
src/source/Environment.h
src/source/Environment.cpp
src/source/Audio.h
src/source/Audio.cpp
src/source/Rotation.h
src/source/Rotation.cpp
src/source/Transform.h
src/source/Transform.cpp
src/source/Camera.h
src/source/Camera.cpp
src/source/blueengine.h
src/source/stb_vorbis.h
src/source/stb_image.h
)

 target_link_libraries(BlueEngine rend)




add_executable(sandbox
src/sandbox/main.cpp
)

target_link_libraries(sandbox BlueEngine)
