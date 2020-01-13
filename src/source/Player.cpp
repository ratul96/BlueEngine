#include "Player.h"
#include "Resources.h"



void Player::onInit()
{
	logo = getCore()->getResources()->loadTexture<Material>("../Whiskers.png");
	std::cout << "Test" << std::endl;
}
void Player::onGui()
{
	std::cout << "Displaying: " << getCore()->getGui() << std::endl;
	getCore()->getGui()->texture(glm::vec4(10,10,100,100), logo);
}
