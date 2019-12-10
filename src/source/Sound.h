#pragma once
#include "AL/al.h"
#include "AL/alc.h"
#include "stb_vorbis.h"
#include "Resource.h"

#include <iostream>
#include <vector>
#include <exception>


class Sound :public Resource
{
public:

	void onLoad(const std::string& fileName);

};
