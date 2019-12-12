#pragma once
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<memory>
#include<iostream>

#define WINDOW_WIDTH 640
#define WINDOW_HEIGHT 480

class Core;

class Screen
{
public:
	static SDL_Window *window;
	SDL_GLContext glContext;

	void ScreenInit();
	void ScreenContext();
	std::weak_ptr<Core> core;


	
};