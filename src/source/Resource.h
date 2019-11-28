#pragma once
#include "Core.h"
#include<iostream>
#include<string>
#include<memory>

class Resource
{
public:
	std::weak_ptr<Core>core;
	virtual void onLoad(std::string &path){}
	
};