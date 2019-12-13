#include "source/blueengine.h"
#include "Renderer.h"
#include "Audio.h"
#include <iostream>
#include <memory>



int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> entity = core->addEntity();
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();
	std::shared_ptr<Audio>audio = entity->addComponent<Audio>();
	//call load function here
	std::shared_ptr<newSound>so = core->getResources()->load<newSound>("W:/gep_sdk-20191121/gep_sdk/BlueEngine/dixie_horn.ogg");
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>("W:/gep_sdk-20191121/gep_sdk/BlueEngine/curuthers.obj");
	// TODO
	tr->setMesh(me);
	audio->setSound(so);
	entity->getComponent<Transform>()->SetPosition(0, 0, -10);
	

	core->run();

	return 0;
}
