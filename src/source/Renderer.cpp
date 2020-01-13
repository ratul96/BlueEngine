#include "Renderer.h"
#include<memory>

/**
* \ brief Initializing Renderer with shaders and buffer initialization
*
*/
void Renderer::onInit()
{
	rendsh = std::make_shared<rend::Shader>();
	b = std::make_shared<rend::Buffer>();
	

	b = getCore()->getContext()->createBuffer(); // create buffer
}
void Renderer::onDisplay()
{
		
		std::shared_ptr<Transform> tr = getEntity()->getComponent<Transform>();
		std::shared_ptr<Camera>cam = getEntity()->getCore()->getCurrentCamera();
		std::shared_ptr<Lighting>li = getEntity()->getCore()->getLight();
		rendsh->setUniform("Model", tr->getModelMat());
		rendsh->setUniform("Projection", cam->getProjMat());
		rendsh->setUniform("View", cam->getViewMat());
		rendsh->setUniform("lightPos",li->getLightPosition());
		rendsh->setUniform("lightColor", li->getLightColour());
		rendsh->setUniform("objectColor", li->getColour());
		rendMesh->setTexture("u_Texture", rendTex);
		rendsh->setMesh(rendMesh);
		rendsh->render();

}
void Renderer::onUpdate()
{
	std::shared_ptr<Transform>tr = getEntity()->getComponent<Transform>();
	std::shared_ptr<Camera>cam = getEntity()->getCore()->getCurrentCamera();
	std::shared_ptr<Lighting>li = getEntity()->getCore()->getLight();
	
	if(getCore()->event.type == SDL_KEYDOWN)
	{
		switch (getCore()->event.key.keysym.sym)
		{
		case SDLK_LEFT:
		{
			getKeyBoard()->RotateLeft = true;
			std::cout << "Left" << std::endl;
			break;
		}
		case SDLK_RIGHT:
		{
			getKeyBoard()->RotateRight = true;
			std::cout << "Right" << std::endl;
			break;
		}
		case SDLK_DOWN:
		{
			getKeyBoard()->RotateDown = true;
			std::cout << "Down" << std::endl;
			break;
		}
		case SDLK_UP:
		{
			getKeyBoard()->RotateUp = true;
			std::cout << "Up" << std::endl;
			break;
		}
		}
		
		
		
		
	}
	if (getCore()->event.type == SDL_KEYUP)
	{
		switch (getCore()->event.key.keysym.sym)
		{
		case SDLK_LEFT:
		{
			getKeyBoard()->RotateLeft = false;
			std::cout << "Left Up" << std::endl;
			break;
		}
		case SDLK_RIGHT:
		{
			getKeyBoard()->RotateRight = false;
			std::cout << "Right Up" << std::endl;
			break;
		}
		case SDLK_DOWN:
		{
			getKeyBoard()->RotateDown = false;
			std::cout << "Down Up" << std::endl;
			break;
		}
		case SDLK_UP:
		{
			getKeyBoard()->RotateUp = false;
			std::cout << "Up released" << std::endl;
			break;
		}
		}
	}
	if (getKeyBoard()->RotateLeft&!getKeyBoard()->RotateRight)
	{
		cam->ChangeCameraAngleY(getCore()->getEnvironment()->getDeltaTime()*0.01f);
	}
	else if (getKeyBoard()->RotateRight & !getKeyBoard()->RotateLeft)
	{
		cam->ChangeCameraAngleY(getCore()->getEnvironment()->getDeltaTime()*-0.01f);
	}

	if (getKeyBoard()->RotateUp & !getKeyBoard()->RotateDown)
	{
		cam->ChangeCameraAngleX(getCore()->getEnvironment()->getDeltaTime()*0.01f);
	}
	else if (getKeyBoard()->RotateDown & !getKeyBoard()->RotateUp)
	{
		cam->ChangeCameraAngleX(getCore()->getEnvironment()->getDeltaTime()*-0.01f);
	}
	li->setLightPosition();
}

void Renderer::setMesh(std::shared_ptr<MeshComponent>_mesh)
{
	                                                            /**Setting the instance of Rend::Mesh inside Renderer to be equivalent to Rend::Mesh inside MeshComponent 
																   */
	this->rendMesh = _mesh->mesh;                                    
}
void Renderer::setMaterial(std::shared_ptr<Material>material)
{
	this->rendTex = material->texture;                         /**Setting the instance of Rend::Texture inside Renderer to be equivalent to Rend::Texture inside MeshComponent 
																   */
}
void Renderer::setShaders(std::shared_ptr<Shaders>sh)
{
	this->rendsh = sh->sh;
}






