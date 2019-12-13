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
"varying vec2 v_TexCoord;                      \n" \
"varying vec3 v_Normal;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  vec3 pos = a_Position;					   \n" \
"  gl_Position = Projection * Model * vec4(pos, 1);  \n" \
"  v_TexCoord = a_TexCoord;                      \n" \
"  v_Normal = a_Normal;                      \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n" \
"#ifdef FRAGMENT                               \n" \
"                                              \n" \
"varying vec2 v_TexCoord;                      \n" \
"varying vec3 v_Normal;                      \n" \
"                                              \n" \
"void main()                                   \n" \
"{                                             \n" \
"  gl_FragColor = vec4(v_TexCoord, 0, 1);      \n" \
"  if(gl_FragColor.x == 0.2) gl_FragColor.x = v_Normal.x; \n" \
"}                                             \n" \
"                                              \n" \
"#endif                                        \n";




Renderer::Renderer()
{
	
	
	
	
}
Renderer::~Renderer()
{
	/*SDL_DestroyWindow(window);
	SDL_Quit();*/

}
void Renderer::onInit()
{


	

	

	//context = Context::initialize(); 
	sh = std::make_shared<rend::Shader>();
	b = std::make_shared<rend::Buffer>();
	sh = getCore()->getContext()->createShader(); // create the shader sh = make_shared<Shader>();
	sh->setSource(shaderSrc);	// set source

	b = getCore()->getContext()->createBuffer(); // create buffer
	/*b->add(vec3(0.0f, 0.5f, 0.0f));
	b->add(vec3(-0.5f, -0.5f, 0.0f));
	b->add(vec3(0.5f, -0.5f, 0.0f));
*/
	
	
}
void Renderer::onDisplay()
{
	//std::shared_ptr<Transform>p = getEntity()->addComponent<Transform>();
	//std::shared_ptr<PositionComponent>pc=getEntity()->getComponent<PositionComponent>();
	//p->createVBO();

	//GLuint vaoId = 0;

	// Create a new VAO on the GPU and bind it
	//glGenVertexArrays(1, &vaoId);

	/*if (!vaoId)
	{
		throw std::exception();
	}

	glBindVertexArray(vaoId);*/


	// set buffer in attribute stream
	// call render

	

	

		//sh->setAttribute("v_Position", b);
		std::shared_ptr<Transform> tr = getEntity()->getComponent<Transform>();
		sh->setUniform("Model", tr->getModelMat());
		sh->setUniform("Projection", perspective(radians(45.0f), 1.0f, 0.1f, 1000.0f));
		//sh->setUniform("View", glm::mat4(1.0f));
		//sh->setAttribute("v_Position", b);
		sh->setMesh(rendMesh);
		sh->render();

		// sh is NULL. Expect crash
		//glUseProgram(programId);
		//glBindVertexArray(vaoId);

		//glDrawArrays(GL_TRIANGLES, 0, 3);

		//glBindVertexArray(0);
		//glUseProgram(0);

		
	

}
void Renderer::setMesh(std::shared_ptr<MeshComponent>_mesh)
{

	this->rendMesh = _mesh->mesh;
}

	






