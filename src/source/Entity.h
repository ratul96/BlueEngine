#pragma once
#include "GL/glew.h"
#include<GLM/glm.hpp>
#include<SDL2/SDL.h>
#include<string>
class Entity
{
public:
	Entity();
	~Entity();
	void updateEntity();
protected:
	std::vector<shared_ptr<Players>> players;

};