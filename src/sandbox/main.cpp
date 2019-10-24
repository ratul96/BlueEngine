#include "source/blueengine.h"

#include <iostream>
#include <memory>

class TriangleRenderer : public Component
{
public:
	TriangleRenderer()
	{

	}
	~TriangleRenderer()
	{

	}
	virtual void onDisplay()
	{
		onDisplay();
	}

	
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();

	//std::shared_ptr<Component> tr = entity->addComponent<Component>();
	std::shared_ptr<TriangleRenderer> tr = entity->addComponent<TriangleRenderer>();

	return 0;
}
