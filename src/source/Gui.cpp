#include "Gui.h"
#include "Core.h"
#include "Resources.h"

Gui::Gui()
{
	shader = getCore()->getResources()->load<Shaders>("../GuiShaders.txt");
}
Gui::~Gui()
{

}
std::shared_ptr<Core>Gui::getCore()
{
	return core.lock();
}

void Gui::texture(glm::vec4 position, std::shared_ptr<Material>texture)
{

}