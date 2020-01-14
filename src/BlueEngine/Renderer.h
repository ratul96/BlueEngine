#pragma once
#include<rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "BlueEngine/Component.h"
#include "BlueEngine/Entity.h"
#include "BlueEngine//Core.h"
#include "BlueEngine/Mesh.h"
#include "BlueEngine/Transform.h"
#include "BlueEngine/Camera.h"
#include "BlueEngine/Material.h"
#include "Shaders.h"
#include "Lighting.h"
#include "Material.h"
#include<memory>
#include <exception>

/**
* \ brief Renderer component. This will be attached to every Entity for it to be displayed on screen.
*
*/


using namespace rend;

class Renderer:public Component
{
public:
	
	
	void onInit();
	void onDisplay();
	void onUpdate();
	
	std::sr1::shared_ptr<rend::Shader> rendsh;
	std::sr1::shared_ptr<rend::Buffer>b;
	std::sr1::shared_ptr<rend::Mesh>rendMesh;
	std::sr1::shared_ptr<rend::Texture>rendTex;
	void setMesh(std::shared_ptr<MeshComponent>_mesh);
	void setMaterial(std::shared_ptr<Material>material);
	void setShaders(std::shared_ptr<Shaders>sh);

   


};
