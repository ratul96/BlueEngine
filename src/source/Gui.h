#pragma once
#include<rend/rend.h>
#include<memory>
#include "Material.h"
#include "Shaders.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Core;

class Gui
{
public:
	Gui();
	~Gui();
	std::shared_ptr<rend::Mesh>mesh;
	glm::mat4 projMatrix;
	std::weak_ptr<Core>core;
	std::shared_ptr<Shaders>shader;
	std::shared_ptr<Core>getCore();
	void texture(glm::vec4 position, std::shared_ptr<Material>texture);
};