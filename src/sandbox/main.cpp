#include "source/blueengine.h"
#include <iostream>
#include <memory>



int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ce = core->addEntity();
	ce->getComponent<Transform>()->SetPosition(0, 0, 10);
	std::shared_ptr<Camera> camera = ce->addComponent<Camera>();
	std::shared_ptr<Entity> entity = core->addEntity();
	entity->addComponent<Rotator>();
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();
	std::shared_ptr<Audio> audio = entity->addComponent<Audio>();
	//call load function here
	std::shared_ptr<NewSound> so = core->getResources()->load<NewSound>("../dixie_horn.ogg");
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>("../curuthers.obj");
	std::shared_ptr<Material>m = core->getResources()->loadTexture<Material>("../Whiskers.png");
	// TODO
	tr->setMesh(me);
	tr->setMaterial(m);
	audio->setSound(so);

	core->run();

	return 0;
}
