#pragma once
#include "AL/al.h"
#include "AL/alc.h"
#include "Resource.h"

#include <iostream>
#include <vector>
#include <exception>
#include "stb_vorbis.h"


class Sound :public Resource
{
public:

	ALuint bufferId;
	void onLoad(const std::string& fileName);

};
