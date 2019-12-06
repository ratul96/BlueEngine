#pragma once
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#include "source/stb_vorbis.h"
#include "source/Component.h"

#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>
#include <vector>
#include <exception>

class Audio :public Component
{
public:
	ALCdevice* device;
	ALCcontext* context;
	ALuint bufferId;
	ALuint sourceID;
	void onaudioInit();
	void load();
};
