#pragma once
#include"GL/glew.h"
#include<SDL2/SDL.h>
#include<memory>
#include<iostream>
#include <vector>

/**
* \ brief Keyboard Input Class. Implementing basic input feature of keyboard for the Engine.
*
*/


class Keyboard
{
private:
	SDL_Event event = { 0 };
public:
	Keyboard();
	~Keyboard();
	static std::shared_ptr<Keyboard> Initialise();
	void isKey();
	bool getKey(int _key);
	void clearKeys();
	std::vector<int>pressedKeys;
	std::vector<int>releasedKeys;
	
	
};