#include "Player.h"
#include "BlueEngine/Resources.h"
#include "BlueEngine/Core.h"
#include "BlueEngine/Gui.h"
#include "BlueEngine/Environment.h"

/**
* \ return type NULL Function initialising the texture/logo to be used for GUI
*
*/
void Player::onInit()
{
	std::string test = getCore()->getEnvironment()->getRootDirectory() + "\\Resources\\" + "\\Whiskers.png";
	logo = getCore()->getResources()->loadTexture<Material>(test.c_str());
	
}
/**
* \ return type NULL Function calling texture function from Gui class, again triggered by polymorphism
*
*/
void Player::onGui()
{
	getCore()->getGui()->texture(logo);
}
