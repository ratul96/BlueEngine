#pragma once
#include "Component.h"
#include "Transform.h"

/**
* \ brief Rotator Component. Attached as a feature for tech demo for the object to Rotate on Y axis
*
*/

class Rotator : public Component
{
public:
	float rot;

	void onInit();

	void onUpdate();
};