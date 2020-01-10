#include "source/blueengine.h"
#include <iostream>
#include <memory>



int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	/**
	* \brief Add camera Entity
	*
	*/

	std::shared_ptr<Entity> ce = core->addEntity();    

	std::shared_ptr<Entity>light = core->addEntity();   /*Add Light Entity
														*
														*/
	std::shared_ptr<Entity> entity = core->addEntity();   /*Add Object Entity
														  *
														  */
	std::shared_ptr<Entity>bcentity = core->addEntity();
	std::shared_ptr<Lighting>lighting = light->addComponent<Lighting>();  /*Add Lighting Component to Light Entity
																		  *
																		  */
	ce->getComponent<Transform>()->SetPosition(0, 0, 10);	/* Setting position of camera
															*
															*/
	std::shared_ptr<Camera> camera = ce->addComponent<Camera>(); /*Adding Camera component
																 *
																 */
	entity->addComponent<Rotator>();
	std::shared_ptr<BoxCollider>bc=bcentity->addComponent<BoxCollider>();
	std::shared_ptr<BoxCollider>bc2 = entity->addComponent<BoxCollider>();
	bcentity->getComponent<Transform>()->SetPosition(0, 0,1);
	bc->setSize(vec3(5, 5, 5));
	bc->setOffset(vec3(0, 0, 3));
	/*bc2->setSize(vec3(20, 20, 20));
	bc2->setOffset(vec3(0, 0, 2));*/
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();
	std::shared_ptr<Renderer>tr2 = bcentity->addComponent<Renderer>();
	std::shared_ptr<Audio> audio = entity->addComponent<Audio>();
	//call load function here
	//std::shared_ptr<NewSound> so = core->getResources()->load<NewSound>("../dixie_horn.ogg");
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>("../curuthers.obj");
	std::shared_ptr<Material>m = core->getResources()->loadTexture<Material>("../Whiskers.png");
	std::shared_ptr<Shaders>sh = core->getResources()->load<Shaders>("../Shaders.txt");
	// TODO
	tr->setMesh(me);
	tr2->setMesh(me);
	tr->setMaterial(m);
	tr2->setMaterial(m);
	tr->setShaders(sh);
	tr2->setShaders(sh);
	//audio->setSound(so);

	core->run();

	return 0;
}
