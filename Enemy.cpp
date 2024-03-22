#include "Enemy.hpp"

Enemy::Enemy() : Entity(glm::vec3(0.0, 1.0, 0.0))
{
    translate(glm::vec2(-0.003f, -0.003f));
}

Enemy::~Enemy()
{

}

void Enemy::update(){
    rotate(-1.0f);
    //translate(glm::vec2(-0.003f, -0.003f));
}