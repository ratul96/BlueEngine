#include "Core.h"
#include "Environment.h"

Environment::Environment()
{
	char stringPath[MAX_PATH];
	GetModuleFileName(NULL, stringPath, MAX_PATH);
	file = stringPath;
	std::size_t location = file.find_last_of("/\\");
	location = file.find("Release");
	root = file.substr(0, location + 7);
	std::cout << root << std::endl;
	
}
Environment::~Environment()
{

}
std::shared_ptr<Core>Environment::getCore()
{
	return core.lock();
}
void Environment::Update()
{
	
	unsigned int current = SDL_GetTicks();
	deltaTs = (float)(current -(getCore()->lastTime)) / 1000.0f;    /**Calculating change in time between previous frame and current frame
																	*/
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