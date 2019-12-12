#pragma once
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<memory>
#include<iostream>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Screen
{
public:
	static SDL_Window *window;

	void init();
};