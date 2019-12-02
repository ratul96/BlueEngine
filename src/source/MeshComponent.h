#pragma once
#include <rend/rend.h>
#include "Resource.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
#include<sr1/memory>
#include<iostream>



using namespace rend;

class MeshComponent :public Resource
{
public:
	MeshComponent();
	~MeshComponent();

	std::shared_ptr<Context> context;
	std::shared_ptr<Shader>shader;
	std::shared_ptr<Mesh>mesh;
	void onLoad(std::string path);
	void onInit();
	


	

	
	
		
		
		
	
};
