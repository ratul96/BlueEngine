#pragma once
#include "Component.h"
#include "Transform.h"

class Rotator : public Component
{
public:
	float rot;

	void onInit();

	void onUpdate();
};