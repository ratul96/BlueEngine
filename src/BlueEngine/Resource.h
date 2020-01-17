#pragma once

#include<iostream>
#include<string>
#include<memory>

/**
* \ brief  Resource System Class.Each Entity will have its own Resource which will act as an interface between the Resources loading system and it's
*		   own individual Resource like Material,Mesh or Shaders
*
*/
class Core;

class Resource
{
public:
	std::weak_ptr<Core>core;
	virtual void onLoad(std::string &path){}
	virtual void onTextureLoad(const char *path){}
	std::string path;
	
};