#pragma once
#include <rend/rend.h>
#include "Resource.h"
#include<string>
#include<memory>
#include<GL/glew.h>
#include<glm/glm.hpp>

class Core;

using namespace rend;

class Shaders :public Resource
{
public:
	std::weak_ptr<Core>core;
	std::shared_ptr<rend::Context>context;
	std::shared_ptr<rend::Shader>sh;
	std::shared_ptr<Core>getCore();
	void onLoad(std::string &path);
	
};