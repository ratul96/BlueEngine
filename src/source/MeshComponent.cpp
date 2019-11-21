#include "MeshComponent.h"
#include <fstream>
#include <iostream>
#include <exception>

MeshComponent::MeshComponent()
{
	std::ifstream file("curuthers.obj");

	if(!file.is_open())
	{
		throw std::exception();
	}

	std::string line;
	while (!file.eof())
	{
		std::getline(file, line);
		obj += line + "\n";
	}
	
		 
}
MeshComponent::~MeshComponent()
{

}
