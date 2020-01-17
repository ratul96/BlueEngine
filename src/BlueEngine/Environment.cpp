#include "Core.h"
#include "Environment.h"

/**
* Constructor to retrieve the root directory of the executable file
*
*/
Environment::Environment()
{
	char stringPath[MAX_PATH];
	GetModuleFileName(NULL, stringPath, MAX_PATH);
	file = stringPath;
	std::size_t location = file.find_last_of("/\\");
	location = file.find("BlueEngine");
	root = file.substr(0, location + 10);
}
Environment::~Environment()
{

}
std::shared_ptr<Core>Environment::getCore()
{
	return core.lock();
}
/**
*return type NULL Calculating change in time between previous frame and current frame
*
*/
void Environment::Update()
{
	
	unsigned int current = SDL_GetTicks();
	deltaTs = (float)(current -(getCore()->lastTime)) / 1000.0f;    
	getCore()->lastTime = current;
}
float Environment::getDeltaTime()
{
	return deltaTs;
}
std::string Environment::getRootDirectory()
{
	return root;
}