#pragma once
#include "Resource.h"
#include<memory>
#include<vector>
#include<iostream>

class Core;

class Resources
{
	
public:
	template <typename T>
	std::shared_ptr<T> load(std::string path)
	{
		std::shared_ptr<T>re = std::make_shared<T>();
		re->core = core;
		re->load(path);

		return re;
	}
	template<typename T>
	std::shared_ptr<T>create()
	{
		std::shared_ptr<T>re1 = std::make_shared<T>();
		resources.push_back(re1);

	}

	std::vector<std::shared_ptr<Resource>>resources;
	std::weak_ptr<Core>core;

};