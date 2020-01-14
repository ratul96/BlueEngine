#include "Player.h"
#include "BlueEngine/Resources.h"
#include "BlueEngine/Core.h"
#include "BlueEngine/Gui.h"



void Player::onInit()
{
	logo = getCore()->getResources()->loadTexture<Material>("../Whiskers.png");
	std::cout << "Test" << std::endl;
}
void Player::onGui()
{
	getCore()->getGui()->texture(logo);
}
