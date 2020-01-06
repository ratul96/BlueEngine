#pragma once
//#ifdef _WIN32
//#include <windows.h>
//#else
//#include <unistd.h>
//#endif


#include "source/Component.h"


#include <AL/al.h>
#include <AL/alc.h>

#include <iostream>
#include <vector>
#include <exception>
#include<memory>


class NewSound;

class Audio :public Component
{
public:
	
	ALuint sourceId;
	void setSound(std::shared_ptr<NewSound>_sn);
	
};
