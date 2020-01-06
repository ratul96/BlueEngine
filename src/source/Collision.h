#pragma once
#include "Component.h"
#include "GL/glew.h"
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <memory>
#include <vector>

class Collision:public Component
{
private:
	bool collideX, collideY, collideZ;
public:
	bool isColliding(glm::vec3 a, glm::vec3 b);
	void Collide();
	/**
																						  *Getting Collision Type Entities
																						  */
	
	
};