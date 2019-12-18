#include "newSound.h"
#include "stb_vorbis.h"


void newSound::onLoad(const std::string& fileName)
{
	alListener3f(AL_POSITION, 0.0f, 0.0f, 0.0f);
	bufferId = 0;
	alGenBuffers(1, &bufferId);

	std::vector<char> buffer;
	ALenum format=0;
	ALsizei freq=0;

	int channels = 0;
	int sampleRate = 0;
	short* output = NULL;

	size_t samples = stb_vorbis_decode_filename(
		fileName.c_str(), &channels, &sampleRate, &output);

	if (samples == -1)
	{
		throw std::exception();
	}

	// Record the sample rate required by OpenAL
	freq = sampleRate;

	// Record the format required by OpenAL
	if (channels == 1)
	{
		format = AL_FORMAT_MONO16;
	}
	else
	{
		format = AL_FORMAT_STEREO16;

		// Force format to be mono (Useful for positional audio)
		// format = AL_FORMAT_MONO16;
		// freq *= 2;
	}

	// Allocate enough space based on short (two chars) multipled by the number of
	// channels and length of clip
	buffer.resize(sizeof(*output) * channels * samples);
	memcpy(&buffer.at(0), output, buffer.size());

	// Clean up the read data
	free(output);

	alBufferData(bufferId, format, &buffer.at(0),
		static_cast<ALsizei>(buffer.size()), freq);
}
