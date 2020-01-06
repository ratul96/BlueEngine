#pragma once
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<memory>
#include<iostream>


class Keyboard
{
public:
	bool RotateLeft = false; bool RotateRight = false; bool RotateUp = false; bool RotateDown = false;
	bool getKeyLeft();
	bool getKeyRight();
	//declare what happens with variable RotateLeft here too
};