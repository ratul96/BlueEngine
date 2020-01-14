#pragma once
#include <BlueEngine/blueengine.h>
#include<memory>

class Player :public Component
{
public:
	void onInit();
	void onGui();
	std::shared_ptr<Material>logo;
};
