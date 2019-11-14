#pragma once
#include<rend/rend.h>
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "source/Component.h"
#include "source/Entity.h"
#include "source/PositionComponent.h"
#include<memory>
#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480



class TriangleRenderer:public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();
	
	
	void onDisplay();

	SDL_Window *window;

	

/*
	std::shared_ptr<Shader>getShader()
	{
		return sh.lock();
	}
*/
   


};
