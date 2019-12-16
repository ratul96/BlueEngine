#include "Transform.h"
#include <SDL2/SDL.h>
Transform::Transform()
{

}
Transform::~Transform()
{

}
void Transform::Update(float deltaTs)
{
	rotation.y += deltaTs * 0.5f;
	while (rotation.y > (3.14159265358979323846 * 2.0))
	{
		rotation.y -= (float)(3.14159265358979323846 * 2.0);
	}

}