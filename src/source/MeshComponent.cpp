#include "MeshComponent.h"
#include <fstream>
#include <iostream>
#include <exception>

MeshComponent::MeshComponent()
{
	
	
		 
}
MeshComponent::~MeshComponent()
{

}
void MeshComponent::onLoad(std::string path)
{
	std::ifstream file(path);

	if (!file.is_open())
	{
		throw std::exception();
	}

	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		path += line + "\n";
	}
	mesh = context->createMesh();
	mesh->parse(path);
	shader->setMesh(mesh);
}
