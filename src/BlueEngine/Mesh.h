#pragma once
#include <rend/rend.h>
#include "Resource.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
#include<memory>
#include<iostream>

/**
* \ brief Material Resource Class used primarily for loading in Texture resources
*
*/

class Core;

using namespace rend;

class MeshComponent :public Resource
{
public:
	

	std::shared_ptr<Context> context;
	std::shared_ptr<Mesh>mesh;
	void onLoad(std::string path);
	std::shared_ptr<Core>getCore();


	

	
	
		
		
		
	
};
