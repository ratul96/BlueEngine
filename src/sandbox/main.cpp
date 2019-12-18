#include "source/blueengine.h"
#include "Renderer.h"
#include "Audio.h"
#include <iostream>
#include <memory>

struct Rotator : public Component
{
  float rot;

  void onInit()
  {
    rot = 0;
  }

  void onUpdate(float getridofme)
  {
    getEntity()->getComponent<Transform>()->SetRotation(0, rot, 0);
    rot += 0.01f;
  }
};

int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ce = core->addEntity();
	ce->getComponent<Transform>()->SetPosition(0, 0, 10);
	std::shared_ptr<Camera> camera = ce->addComponent<Camera>();

	std::shared_ptr<Entity> entity = core->addEntity();
	entity->addComponent<Rotator>();
	//ce->addComponent<Rotator>();
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();
	std::shared_ptr<Audio> audio = entity->addComponent<Audio>();
	//call load function here
	std::shared_ptr<newSound> so = core->getResources()->load<newSound>("dixie_horn.ogg");
	so = core->getResources()->load<newSound>("dixie_horn.ogg");
	so = core->getResources()->load<newSound>("dixie_horn.ogg");
	so = core->getResources()->load<newSound>("dixie_horn.ogg");
	so = core->getResources()->load<newSound>("dixie_horn.ogg");
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>("curuthers.obj");
	//std::shared_ptr<Material>m = core->getResources()->loadTexture<Material>("Whiskers.png");
	std::shared_ptr<Material>m = core->getResources()->loadTexture<Material>("../Whiskers.png");
	// TODO
	tr->setMesh(me);
	tr->setMaterial(m);
	audio->setSound(so);

	core->run();

	return 0;
}
