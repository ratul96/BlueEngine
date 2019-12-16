#pragma once
#include <rend/rend.h>
#include "Resource.h"
#include<string>
#include<memory>
#include<GL/glew.h>
#include<glm/glm.hpp>


class Core;

using namespace rend;

class Material:public Resource
{
public:
	std::shared_ptr<Context>context;
	std::shared_ptr<Texture>texture;
	void onTextureLoad(const char *path);
	std::shared_ptr<Core>getCore();


	

};