#pragma once
#include<rend/rend.h>
#include<memory>
#include "Material.h"
#include "Shaders.h"
#include "GL/glew.h"
#include<glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

/**
* \ brief Graphics User Interface Class. Implementing a basic faeture for GUI
*
*/


class Core;

class Gui
{
public:
	Gui(std::shared_ptr<Core> c);
	~Gui();
	std::shared_ptr<rend::Mesh>mesh;
	glm::mat4 projMatrix;
	std::shared_ptr<Buffer>buffer;
	std::weak_ptr<Core>core;
	std::shared_ptr<Shaders>shader;
	std::shared_ptr<Core>getCore();
	void texture(std::shared_ptr<Material>texture);
};
