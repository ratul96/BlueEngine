#include "Renderer.h"
#include "Environment.h"
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
		rendMesh->setTexture("u_Texture", rendTex);
		rendsh->setMesh(rendMesh);
		rendsh->render();

}
void Renderer::onUpdate()
{
	std::shared_ptr<Transform>tr = getEntity()->getComponent<Transform>();
	std::shared_ptr<Camera>cam = getEntity()->getCore()->getCurrentCamera();
	std::shared_ptr<Lighting>li = getEntity()->getCore()->getLight();
	
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






