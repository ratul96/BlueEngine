#pragma once
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<memory>
#include<iostream>
#include <vector>


class Keyboard
{
public:
	Keyboard();
	~Keyboard();
	bool getKey(int key);
	const Uint8 *key;
	std::vector<int>pressedKeys;
	bool RotateLeft = false; bool RotateRight = false; bool RotateUp = false; bool RotateDown = false;
	
};