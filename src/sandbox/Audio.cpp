#pragma once
#include "Audio.h"
void Audio::onaudioInit()
{
	ALCdevice* device = alcOpenDevice(NULL);

	if (device == NULL)
	{
		throw std::exception();
	}
	ALCcontext* context = alcCreateContext(device, NULL);

	if (context == NULL)
	{
		alcCloseDevice(device);
		throw std::exception();
	}

	// Set as current context
	if (!alcMakeContextCurrent(context))
	{
		alcDestroyContext(context);
		alcCloseDevice(device);
		throw std::exception();
	}

}

