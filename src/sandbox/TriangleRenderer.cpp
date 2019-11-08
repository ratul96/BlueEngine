#include "TriangleRenderer.h"
#include "source/PositionComponent.h"



const GLchar* vertexShaderSrc =
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
"";

const GLchar* fragmentShaderSrc =
"varying vec4 ex_Color;" \
"void main()" \
"{" \
"  gl_FragColor = ex_Color;" \
"}" \
"";




TriangleRenderer::TriangleRenderer()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
        {
                throw std::exception();
        }

        SDL_Window* window = SDL_CreateWindow("Lab 4 - Architecture",
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

	// create the shader sh = make_shared<Shader>();
	// make rend context
	// set source
	// create buffer
}
TriangleRenderer::~TriangleRenderer()
{
	SDL_DestroyWindow(window);
	SDL_Quit();

}
void TriangleRenderer::onDisplay()
{
	std::shared_ptr<PositionComponent>p = getEntity()->addComponent<PositionComponent>();
	//std::shared_ptr<PositionComponent>pc=getEntity()->getComponent<PositionComponent>();
	p->createVBO();
	
	GLuint vaoId = 0;

	// Create a new VAO on the GPU and bind it
	glGenVertexArrays(1, &vaoId);

	if (!vaoId)
	{
		throw std::exception();
	}

	glBindVertexArray(vaoId);

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

		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// sh is NULL. Expect crash
		glUseProgram(sh->programId);
		glBindVertexArray(vaoId);

		glDrawArrays(GL_TRIANGLES, 0, 3);

		glBindVertexArray(0);
		glUseProgram(0);

		SDL_GL_SwapWindow(window);
	}



	
}





