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
	static std::shared_ptr<Keyboard> Initialise();
	void isKey(int key);
	bool getKey(int _key);
	void clearKeys();
	std::vector<int>pressedKeys;
	std::vector<int>releasedKeys;
	bool RotateLeft = false; bool RotateRight = false; bool RotateUp = false; bool RotateDown = false;
	
};