#include "Entity.hpp"

Entity::Entity(glm::vec3 c)
{
    _transform = glm::mat4(1.0f);
    _color = c;
}

Entity::~Entity()
{
}

void Entity::translate(glm::vec2 vec){
    _pos.x += vec.x;
    _pos.y += vec.y;
}

void Entity::_update(){
    _transform = glm::translate(glm::mat4(1.0f), _pos);
    _transform = glm::rotate(_transform, glm::radians(_angle), glm::vec3(0.0f, 0.0f, 1.0f));
    
}

void Entity::rotate(float rot){
    _angle += rot;
}

glm::mat4 Entity::getTransform(){
    return _transform;
}

glm::vec3 Entity::getColor(){
    return _color;
}

void Entity::setColor(glm::vec3 vec){
    _color = vec;
}


