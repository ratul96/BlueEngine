#pragma once
#include<rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "source/Component.h"
#include "source/Entity.h"
#include "source//Core.h"
#include "source/Transform.h"
#include "source/Mesh.h"
#include "source/Transform.h"
#include<memory>
#include <exception>



using namespace rend;

class Renderer:public Component
{
public:
	Renderer();
	~Renderer();
	
	void onInit();
	void onDisplay();
	


	//std::shared_ptr<Context> context; // make rend context
	
	std::sr1::shared_ptr<rend::Shader> sh;
	std::sr1::shared_ptr<rend::Buffer>b;
	std::sr1::shared_ptr<rend::Mesh>rendMesh;
	void setMesh(std::shared_ptr<MeshComponent>_mesh);

	//std::weak_ptr<Core>core;

	//std::shared_ptr<Core>getCore();
	
/*
	std::shared_ptr<Shader>getShader()
	{
		return sh.lock();
	}
*/
   


};
