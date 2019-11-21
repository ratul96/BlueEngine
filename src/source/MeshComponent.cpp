#include "MeshComponent.h"
#include <fstream>
#include<iostream>

MeshComponent::MeshComponent()
{
	obj = "curuthers.obj";

	std::ifstream file(obj);
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
