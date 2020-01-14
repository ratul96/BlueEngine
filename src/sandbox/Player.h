#pragma once
#include "BlueEngine/Component.h"
#include "BlueEngine/Material.h"
#include<memory>

class Player:public Component
{
public:
	void onInit();
	void onGui();
	std::shared_ptr<Material>logo;
};
