#include"Scene.hpp"

Scene::Scene()
{

}

Scene::~Scene()
{
    /*
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        delete entities[i];
    }
    */
}

void Scene::addEntity(Entity *e){
    entities.push_back(e);
}

void Scene::update(){
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        entities[i]->update();
        entities[i]->_update();
    }
}

void Scene::draw(Shader* s){
    for (unsigned int i = 0; i < entities.size(); i++)
    {
        glm::mat4 model = entities[i]->getTransform();
        s->setMat4("model", model);
        glm::vec3 color = entities[i]->getColor();
        s->setVec3("col", color);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    }
}