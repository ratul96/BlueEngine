#pragma once
#include "Component.h"
#include "Material.h"
#include<memory>

class Player :public Component
{
public:
	void onInit();
	void onGui();
	std::shared_ptr<Material>logo;
};