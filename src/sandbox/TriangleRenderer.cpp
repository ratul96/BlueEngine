#include "TriangleRenderer.h"




const GLchar* shaderSrc =
"#ifdef VERTEX\n"
"attribute vec3 in_Position;" \
"attribute vec4 in_Color;" \
"" \
"varying vec4 ex_Color;" \
"" \
"void main()" \
"{" \
"  gl_Position = vec4(in_Position, 1.0);" \
"  ex_Color = in_Color;" \
"}" \
"\n#else\n" \
"varying vec4 ex_Color;" \
"void main()" \
"{" \
"  gl_FragColor = ex_Color;" \
"}" \
"\n#endif\n";




TriangleRenderer::TriangleRenderer()
{
	
	
	
	
}
TriangleRenderer::~TriangleRenderer()
{
	SDL_DestroyWindow(window);
	SDL_Quit();

}
void TriangleRenderer::onInit()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		throw std::exception();
	}

	window = SDL_CreateWindow("Lab 4 - Architecture",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window))
	{
		throw std::exception();
	}

	if (glewInit() != GLEW_OK)
	{
		throw std::exception();
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(window);

	if (!glContext)
	{
		std::cout << "Failed to create OpenGL context" << std::endl;
	}

	context = Context::initialize(); 

	sh = context->createShader(); // create the shader sh = make_shared<Shader>();
	b = context->createBuffer(); // create buffer


	sh->setSource(shaderSrc);	// set source


	b->add(vec3(0.0f, 0.5f, 0.0f));
	b->add(vec3(-0.5f, -0.5f, 0.0f));
	b->add(vec3(0.5f, -0.5f, 0.0f));

	object->parse(mesh->obj);
}
void TriangleRenderer::onDisplay()
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

	bool quit = false;

	while (!quit)
	{
		SDL_Event event = { 0 };

		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				quit = true;
			}
		}

		glClearColor(1.0f, 1.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		sh->setAttribute("in_Position", b);
		sh->render();

		// sh is NULL. Expect crash
		//glUseProgram(programId);
		//glBindVertexArray(vaoId);

		//glDrawArrays(GL_TRIANGLES, 0, 3);

		//glBindVertexArray(0);
		//glUseProgram(0);

		SDL_GL_SwapWindow(window);
	}



	
}





