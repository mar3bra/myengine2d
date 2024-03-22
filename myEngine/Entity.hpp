#ifndef ENTITY_HPP
#define ENTITY_HPP
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <iostream>
class Entity
{
private:
    glm::mat4 _transform;
    glm::vec3 _color;
    glm::vec3 _pos;
    float _angle;
public:
    Entity(glm::vec3 c);
    ~Entity();
    void translate(glm::vec2 vec);
    void rotate(float rot);
    virtual void update() = 0;
    void _update();
    glm::mat4 getTransform();
    glm::vec3 getColor();
    void setColor(glm::vec3 vec);

};

#endif