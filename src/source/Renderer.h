#pragma once
#include<rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "source/Component.h"
#include "source/Entity.h"
#include "source//Core.h"
#include "source/Mesh.h"
#include "source/Transform.h"
#include "source/Camera.h"
#include "source/Material.h"
#include "Shaders.h"
#include "Lighting.h"
#include<memory>
#include <exception>



using namespace rend;

class Renderer:public Component
{
public:
	
	
	void onInit();
	void onDisplay();
	void onUpdate();
	


	//std::shared_ptr<Context> context; // make rend context
	
	std::sr1::shared_ptr<rend::Shader> rendsh;
	std::sr1::shared_ptr<rend::Buffer>b;
	std::sr1::shared_ptr<rend::Mesh>rendMesh;
	std::sr1::shared_ptr<rend::Texture>rendTex;
	void setMesh(std::shared_ptr<MeshComponent>_mesh);
	void setMaterial(std::shared_ptr<Material>material);
	void setShaders(std::shared_ptr<Shaders>sh);

   


};
