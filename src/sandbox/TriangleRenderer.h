#pragma once
#include <SDL2/SDL.h>
#include <GL/glew.h>
#include "source/Component.h"
#include "source/Entity.h"

#include <exception>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480



class TriangleRenderer:public Component
{
public:
	TriangleRenderer();
	~TriangleRenderer();
	
	
	void DrawTriangle();

	SDL_Window *window;

	
	


};