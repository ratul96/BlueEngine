#pragma once

#include<iostream>
#include<string>
#include<memory>

class Core;

class Resource
{
public:
	std::weak_ptr<Core>core;
	virtual void onLoad(std::string &path){}
	
};