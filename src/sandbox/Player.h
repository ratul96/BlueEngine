#pragma once
#include "BlueEngine/Component.h"
#include "BlueEngine/Material.h"
#include<memory>
/**
* \ brief Player, a component used primarily for displaying GUI triggered by virtue of polymorphism
*
*/
class Player:public Component
{
public:
	void onInit();
	void onGui();
	std::shared_ptr<Material>logo;
};
