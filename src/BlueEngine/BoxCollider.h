#include "Component.h"

#include "GL/glew.h"
#include<glm/glm.hpp>

/**
* \ brief Collision Detection detected by BoxCollider Component
*
*/


class BoxCollider : public Component
{
public:
  void onInit();

  void setOffset(glm::vec3 offset);
  void setSize(glm::vec3 size);

private:
  void onUpdate();
  void collideBox();

 glm::vec3 size;
  glm::vec3 offset;
  glm::vec3 lastPosition;

  bool isColliding(glm::vec3 position, glm::vec3 size);

 glm::vec3 getCollisionResponse(glm::vec3 position,
    glm::vec3 size);
};
