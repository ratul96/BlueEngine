#include "Player.h"
#include "Resources.h"



void Player::onInit()
{
	logo = getCore()->getResources()->loadTexture<Material>("../Whiskers.png");
}
void Player::onGui()
{
	getCore()->getGui()->texture(glm::vec4(10,10,100,100), logo);
	std::cout << "Displaying" << std::endl;
}