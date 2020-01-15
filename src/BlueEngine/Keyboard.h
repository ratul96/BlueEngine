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
	void Initialise();
	void isKey(int key);
	bool getKey(int _key);
	const Uint8 *key;
	std::vector<int>pressedKeys;
	std::vector<int>keys;
	std::vector<int>ListOfKeys;
	bool RotateLeft = false; bool RotateRight = false; bool RotateUp = false; bool RotateDown = false;
	
};