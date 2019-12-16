#pragma once
#include "Audio.h"
#include "source/newSound.h"
void Audio::setSound(std::shared_ptr<newSound>_sn)
{
	sourceId = 0;
	alGenSources(1, &sourceId);

	alSource3f(sourceId, AL_POSITION, 0.0f, 5.0f, 0.0f);
	alSourcei(sourceId, AL_BUFFER, _sn->bufferId);
	alSourcePlay(sourceId);
	while (true)
	{
		ALint state = 0;
		alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			break;
		}

	}

}

