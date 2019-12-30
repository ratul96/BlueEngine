#include "Audio.h"
#include "source/newSound.h"
void Audio::setSound(std::shared_ptr<NewSound>_sn)
{
	sourceId = 0;
	alGenSources(1, &sourceId);

	std::cout << "Source: " << sourceId << std::endl;

	alSource3f(sourceId, AL_POSITION, 0.0f, 5.0f, 0.0f);

	std::cout << "Buffer: " << _sn->bufferId << std::endl;

	alSourcei(sourceId, AL_BUFFER, _sn->bufferId);
	alSourcePlay(sourceId);

	/* TODO: Check if file finished, move to ontick */
/*
	while (true)
	{
		ALint state = 0;
		alGetSourcei(sourceId, AL_SOURCE_STATE, &state);

		if (state == AL_STOPPED)
		{
			break;
		}

	}
*/

}

