#include "Gui.h"
#include "Core.h"
#include "Resources.h"
#include "Environment.h"
/**
*\ return type Constructor. Setting Gui to use the corresponding Shader setting up rend Context and Buffer positions.Also setting up Core reference
*
*/
Gui::Gui(std::shared_ptr<Core> c)
{
	core = c;
	shader = getCore()->getResources()->load<Shaders>(getCore()->getEnvironment()->getRootDirectory() + "\\Resources\\" + "\\GuiShaders.txt");
	buffer = getCore()->getContext()->createBuffer();
	mesh = getCore()->getContext()->createMesh();
	
	buffer->add(vec2(0, 0));
	buffer->add(vec2(0, 1));
	buffer->add(vec2(1, 1));

	buffer->add(vec2(1, 1));
	buffer->add(vec2(1, 0));
	buffer->add(vec2(0, 0));
	mesh->setBuffer("a_Position", buffer);
}
Gui::~Gui()
{

}
std::shared_ptr<Core>Gui::getCore()
{
	return core.lock();
}
/**
*\ return type Constructor. Setting up Model Matrix and Projection Matrix to render the mesh.
*
*/
void Gui::texture(std::shared_ptr<Material>texture)
{
	shader->sh->setUniform("u_Model", glm::scale(glm::mat4(1.0f), glm::vec3(100.0f, 100.0f, 1.0f)));
	shader->sh->setUniform("u_Projection", glm::ortho(0.0f, 800.0f, 600.0f, 0.0f, -1.0f, 1.0f));
	shader->sh->setMesh(mesh);
	shader->sh->render();
}
