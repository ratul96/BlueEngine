#pragma once
#include "BlueEngine/Component.h"


#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>
#include <vector>
#include <exception>
#include<memory>

class NewSound;

/**
* \ brief Audio class for loading audio feature
*
*/


class Audio :public Component
{
public:
	
	ALuint sourceId;
	void setSound(std::shared_ptr<NewSound>_sn);
	
};
