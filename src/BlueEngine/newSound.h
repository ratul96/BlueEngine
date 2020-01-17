#pragma once
#include "AL/al.h"
#include "AL/alc.h"
#include "Resource.h"

#include <iostream>
#include <vector>
#include <exception>

/**
* \ brief Sound Resource Class used primarily for loading in Audio
*
*/

class NewSound :public Resource
{
public:

	ALuint bufferId;
	void onLoad(const std::string& fileName);

};
