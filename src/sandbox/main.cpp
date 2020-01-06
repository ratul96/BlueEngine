#include "source/blueengine.h"
#include <iostream>
#include <memory>



int main()
{
	std::shared_ptr<Core> core = Core::initialize();

	std::shared_ptr<Entity> ce = core->addEntity();    /*Add camera Entity
													   *
													   */

	std::shared_ptr<Entity>light = core->addEntity();   /*Add Light Entity
														*
														*/
	std::shared_ptr<Entity> entity = core->addEntity();   /*Add Object Entity
														  *
														  */
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
	
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();
	std::shared_ptr<Audio> audio = entity->addComponent<Audio>();
	//call load function here
	//std::shared_ptr<NewSound> so = core->getResources()->load<NewSound>("../dixie_horn.ogg");
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>("../curuthers.obj");
	std::shared_ptr<Material>m = core->getResources()->loadTexture<Material>("../Whiskers.png");
	std::shared_ptr<Shaders>sh = core->getResources()->load<Shaders>("../Shaders.txt");
	// TODO
	tr->setMesh(me);
	tr->setMaterial(m);
	tr->setShaders(sh);
	//audio->setSound(so);

	core->run();

	return 0;
}
