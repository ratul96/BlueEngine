#pragma once
#include<rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "source/Component.h"
#include "source/Entity.h"
#include "source/Transform.h"
#include "source/MeshComponent.h"
#include "source/Transform.h"
#include<sr1/memory>
#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

using namespace rend;

class Renderer:public Component
{
public:
	Renderer();
	~Renderer();
	
	void onInit();
	void onDisplay();
	
	SDL_Window *window;

	std::shared_ptr<Context> context; // make rend context
	
	std::sr1::shared_ptr<rend::Shader> sh;
	std::sr1::shared_ptr<rend::Buffer>b;
	//std::sr1::shared_ptr<Mesh>object;
	void setMesh(std::shared_ptr<MeshComponent>mesh);
	
/*
	std::shared_ptr<Shader>getShader()
	{
		return sh.lock();
	}
*/
   


};
