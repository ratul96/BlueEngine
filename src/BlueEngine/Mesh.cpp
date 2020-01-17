#include "Mesh.h"
#include "Core.h"
#include <fstream>
#include <iostream>
#include <exception>

/**
* \ return type shared pointer reference to Core
*
*/
std::shared_ptr<Core>MeshComponent::getCore()
{
	return core.lock();
}
/**
* \ return type NULL Function for loading in Mesh by reading .obj file 
*
*/
void MeshComponent::onLoad(std::string path)
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
	
	mesh=getCore()->getContext()->createMesh();
	mesh->parse(path);
	
}
