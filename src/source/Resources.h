#pragma once
#include "Resource.h"
#include<memory>
#include<vector>
#include<iostream>

class Resources
{
	
public:
	template <typename T>
	std::shared_ptr<T>load(std::string path)
	{
		std::shared_ptr<T>re = std::make_shared<T>();
		//resources.push_back(re);
		re->core = core;
		re->load(path);
	}

	std::vector<std::shared_ptr<Resource>>resources;

};