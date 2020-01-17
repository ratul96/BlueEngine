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
src/BlueEngine/Core.h
src/BlueEngine/Screen.h
src/BlueEngine/Keyboard.h
src/BlueEngine/Keyboard.cpp
src/BlueEngine/BoxCollider.h
src/BlueEngine/BoxCollider.cpp
src/BlueEngine/Gui.h
src/BlueEngine/Gui.cpp
src/BlueEngine/NewSound.h
src/BlueEngine/NewSound.cpp
src/BlueEngine/Component.h
src/BlueEngine/Component.cpp
src/BlueEngine/Entity.h
src/BlueEngine/Core.cpp
src/BlueEngine/Lighting.h
src/BlueEngine/Lighting.cpp
src/BlueEngine/Mesh.h
src/BlueEngine/Mesh.cpp
src/BlueEngine/Entity.cpp
src/BlueEngine/Material.h
src/BlueEngine/Material.cpp
src/BlueEngine/Resource.h
src/BlueEngine/Resources.h
src/BlueEngine/Renderer.h
src/BlueEngine/Shaders.h
src/BlueEngine/Shaders.cpp
src/BlueEngine/Renderer.cpp
src/BlueEngine/Environment.h
src/BlueEngine/Environment.cpp
src/BlueEngine/Audio.h
src/BlueEngine/Audio.cpp
src/BlueEngine/Rotation.h
src/BlueEngine/Rotation.cpp
src/BlueEngine/Transform.h
src/BlueEngine/Transform.cpp
src/BlueEngine/Camera.h
src/BlueEngine/Camera.cpp
src/BlueEngine/blueengine.h
src/BlueEngine/stb_vorbis.h
src/BlueEngine/stb_image.h
)

 target_link_libraries(BlueEngine rend)




add_executable(sandbox
src/sandbox/main.cpp
src/sandbox/Player.cpp
src/sandbox/Player.h
)

target_link_libraries(sandbox BlueEngine)
