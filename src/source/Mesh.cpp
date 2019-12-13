#include "Mesh.h"
#include "Core.h"
#include <fstream>
#include <iostream>
#include <exception>

MeshComponent::MeshComponent()
{
	// use on init
	/*mesh = context->createMesh();*/
		 
}
MeshComponent::~MeshComponent()
{

}
void MeshComponent::onInit()
{

}
std::shared_ptr<Core>MeshComponent::getCore()
{
	return core.lock();
}
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
