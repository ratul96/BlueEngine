#include "Renderer.h"
#include<memory>




const GLchar* shaderSrc =
"#ifdef VERTEX                                 \n" \
"                                              \n" \
"attribute vec3 a_Position;                    \n" \
"attribute vec2 a_TexCoord;					   \n" \
"attribute vec3 a_Normal;					   \n" \
"                                              \n" \
"uniform mat4 Projection;                      \n" \
"uniform mat4 Model;                           \n" \
"uniform mat4 View;                            \n" \
"varying vec2 v_TexCoord;                      \n" \
"varying vec3 v_Normal;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  vec3 pos = a_Position;					   \n" \
"  gl_Position = Projection*View*Model*vec4(pos, 1);  \n" \
"  v_TexCoord = a_TexCoord;                      \n" \
"  v_Normal = a_Normal;                          \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"uniform sampler2D u_Texture;                  \n" \
"varying vec2 v_TexCoord;                      \n" \
"varying vec3 v_Normal;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = texture2D(u_Texture,v_TexCoord);      \n" \
"  if(gl_FragColor.x == 0.2) gl_FragColor.x = v_Normal.x; \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";




Renderer::Renderer()
{
	
	
	
	
}
Renderer::~Renderer()
{
	

}
void Renderer::onInit()
{


	

	

	
	sh = std::make_shared<rend::Shader>();
	b = std::make_shared<rend::Buffer>();
	sh = getCore()->getContext()->createShader(); // create the shader
	sh->setSource(shaderSrc);	// set source

	b = getCore()->getContext()->createBuffer(); // create buffer
	
	
	
}
void Renderer::onDisplay()
{
	
	

	

		
		std::shared_ptr<Transform> tr = getEntity()->getComponent<Transform>();
		std::shared_ptr<Camera>cam = getEntity()->getCore()->getCurrentCamera();
		sh->setUniform("Model", tr->getModelMat());
		sh->setUniform("Projection", cam->getProjMat()); 
		sh->setUniform("View", cam->getViewMat());
		rendMesh->setTexture("u_Texture", rendTex);
		sh->setMesh(rendMesh);
		sh->render();

		

		
	

}
void Renderer::onUpdate()
{
	std::shared_ptr<Transform>tr = getEntity()->getComponent<Transform>();
	std::shared_ptr<Camera>cam = getEntity()->getCore()->getCurrentCamera();
	
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
		cam->ChangeCameraAngleY(getCore()->getEnvironment()->getDeltaTime()*1.0f);
	}
	else if (getKeyBoard()->RotateRight & !getKeyBoard()->RotateLeft)
	{
		cam->ChangeCameraAngleY(getCore()->getEnvironment()->getDeltaTime()*-1.0f);
	}

	if (getKeyBoard()->RotateUp & !getKeyBoard()->RotateDown)
	{
		cam->ChangeCameraAngleX(getCore()->getEnvironment()->getDeltaTime()*1.0f);
	}
	else if (getKeyBoard()->RotateDown & !getKeyBoard()->RotateUp)
	{
		cam->ChangeCameraAngleX(getCore()->getEnvironment()->getDeltaTime()*-1.0f);
	}
	
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
	





