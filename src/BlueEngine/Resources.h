#pragma once
#include "Resource.h"
#include<memory>
#include<vector>
#include<iostream>

/**
* \ brief Resources and Caching system for loading in the correct file and avoiding loading same file twice. This class is designed to add the functionality of loading different types of object resources.
*
*/

class Core;

class Resources
{
	
public:
	template <typename T>
	std::shared_ptr<T> load(std::string path)
	{
		for (size_t ri = 0; ri < resources.size(); ri++)
		{
			if (resources.at(ri)->path == path)
			{
				return std::dynamic_pointer_cast<T>(resources.at(ri));
			}
		}
		std::shared_ptr<T>re = std::make_shared<T>();
		re->core = core;
		re->path = path;
		re->onLoad(path);
		resources.push_back(re);

		return re;
	}
	template<typename T>
	std::shared_ptr<T>loadTexture(const char *path)
	{
		std::shared_ptr<T>re = std::make_shared<T>();
		re->core = core;
		re->onTextureLoad(path);

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