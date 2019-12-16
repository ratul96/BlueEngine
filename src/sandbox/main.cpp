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
	//std::shared_ptr<newSound>so = core->getResources()->load<newSound>("F:/gep_sdk-20191121/gep_sdk/BlueEngine/dixie_horn.ogg");
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>("F:/gep_sdk-20191121/gep_sdk/BlueEngine/curuthers.obj");
	std::shared_ptr<Material>m = core->getResources()->loadTexture<Material>("F:/gep_sdk-20191121/gep_sdk/BlueEngine/Whiskers.png");
	// TODO
	tr->setMesh(me);
	tr->setMaterial(m);
	//audio->setSound(so);
	

	core->run();

	return 0;
}
