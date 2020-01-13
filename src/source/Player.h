#pragma once
#include <source/blueengine.h>
#include<memory>

class Player :public Component
{
public:
	void onInit();
	void onGui();
	std::shared_ptr<Material>logo;
};
