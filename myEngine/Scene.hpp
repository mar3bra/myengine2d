#ifndef SCENE_HPP
#define SCENE_HPP
#include "Entity.hpp"
#include <vector>
#include "Shader.hpp"

class Scene
{
private:
    std::vector<Entity*> entities;
public:
    Scene();
    ~Scene();
    void addEntity(Entity *e);
    void update();
    void draw(Shader* s);
};


#endif