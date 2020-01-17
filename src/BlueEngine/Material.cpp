#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
#include "Material.h"
#include "Core.h"
#include <SDL2/SDL.h>
/**
* \ return type shared pointer reference to Core
*
*/
std::shared_ptr<Core>Material::getCore()
{
	return core.lock();
}
/**
* \ return type NULL Function for loading in texture
*
*/
void Material::onTextureLoad(const char *path)
{
	texture = getCore()->getContext()->createTexture();

	int w = 0;
	int h = 0;
	int bpp = 0;

	unsigned char *data = stbi_load(path,
		&w, &h, &bpp, 3);

	if (!data)
	{
		throw Exception("Failed to open image");
	}

	texture->setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			texture->setPixel(x, y, vec3(
				data[r] / 255.0f,
				data[r + 1] / 255.0f,
				data[r + 2] / 255.0f));
		}
	}

	stbi_image_free(data);
}
	
