#include "BlueEngine/blueengine.h"
#include <iostream>
#include <memory>

/**
* \ brief Orbiter component having both the object and the light revolve around a static object
*
*/

struct Orbiter :public Component
{
	float lightX, lightY, lightZ;
	float rot;

	void onInit()
	{ 
		rot = 0;
		lightX = 0;
		lightY = 0;
		lightZ = 0;
	}
	void onUpdate()
	{
		
		getEntity()->getComponent<Transform>()->SetPosition(lightX, lightY, lightZ);
		
		lightX = sin(SDL_GetTicks()) * 2.0f;
		lightY = -0.3f;
		lightZ = cos(SDL_GetTicks()) * 2.5f;

		
	}
};



int main()
{
	/**
	* \brief Initializing Core
	*
	*/
	std::shared_ptr<Core> core = Core::initialize();

	/**
	* \brief Add camera Entity
	*
	*/

	std::shared_ptr<Entity> ce = core->addEntity();   
	/**
	* \brief Add Light Entity
	*
	*/
	std::shared_ptr<Entity>light = core->addEntity();
	/**
	* \brief Add Player Entity
	*
	*/
	std::shared_ptr<Entity> entity = core->addEntity();
	/**
	*\brief Add Lighting Component
	*
	*/																	  
	std::shared_ptr<Lighting>lighting = light->addComponent<Lighting>();  
	/**
	*\brief Setting Position of the camera
	*
	*/
	ce->getComponent<Transform>()->SetPosition(0, 0, 10);	
	std::shared_ptr<Camera> camera = ce->addComponent<Camera>(); /*Adding Camera component
																 *
																 */
	ce->addComponent<Player>();
	//entity->addComponent<Rotator>();
	/*std::shared_ptr<BoxCollider>bc=bcentity->addComponent<BoxCollider>();
	std::shared_ptr<BoxCollider>bc2 = entity->addComponent<BoxCollider>();*/
	light->addComponent<Orbiter>();
	/*bc->setSize(vec3(0.1, 0.1, 0.1));
	bc->setOffset(vec3(0, 0, 3));*/
	/*bc2->setSize(vec3(20, 20, 20)); 
	bc2->setOffset(vec3(0, 0, 2));*/
	
	std::shared_ptr<Renderer> tr = entity->addComponent<Renderer>();
	std::shared_ptr<Renderer>tr2 = light->addComponent<Renderer>();
	std::shared_ptr<Audio> audio = entity->addComponent<Audio>();
	//call load function here
	std::shared_ptr<NewSound> so = core->getResources()->load<NewSound>(core->getEnvironment()->getRootDirectory()+"\\dixie_horn.ogg");
	std::shared_ptr<MeshComponent>me = core->getResources()->load<MeshComponent>(core->getEnvironment()->getRootDirectory()+"\\curuthers.obj");
	std::string test = core->getEnvironment()->getRootDirectory() + "\\Whiskers.png";
	std::shared_ptr<Material>m = core->getResources()->loadTexture<Material>(test.c_str());
	
	std::shared_ptr<Shaders>sh = core->getResources()->load<Shaders>(core->getEnvironment()->getRootDirectory()+"\\Shaders.txt");
	std::shared_ptr<Shaders>sh2= core->getResources()->load<Shaders>(core->getEnvironment()->getRootDirectory()+"\\NormalShaders.txt");
	// TODO
	tr->setMesh(me);
	tr2->setMesh(me);
	tr->setMaterial(m);
	tr2->setMaterial(m);
	tr->setShaders(sh);
	tr2->setShaders(sh2);
	
	//audio->setSound(so);

	core->run();

	return 0;
}
