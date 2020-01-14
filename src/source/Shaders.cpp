#include "Shaders.h"
#include "Core.h"
#include "Lighting.h"
#include <fstream>

std::shared_ptr<Core>Shaders::getCore()
{
	return core.lock();
}
void Shaders::onLoad(std::string &path)
{
	std::ifstream file(path);

	if (!file.is_open())
	{
		throw std::exception();
	}
	path = "";
	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		path += line + "\n";
	}
	sh = getCore()->getContext()->createShader(); // create the shader
	sh->setSource(path);	// set source
}
//void Shaders::Apply()
//{
//	std::shared_ptr<Lighting>li = getCore()->getLight();
//	sh->setUniform("lightPos", li->getLightPosition());
//	sh->setUniform("lightColor", vec3(1, 0, 0));
//	sh->setUniform("objectColor", li->getColour());
//}