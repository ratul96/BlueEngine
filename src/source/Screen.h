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
	 SDL_Window *window;
	SDL_GLContext glContext;
};