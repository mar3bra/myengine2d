#include "Player.hpp"
Player::Player() : Entity(glm::vec3(1.0, 0.0, 0.0)){
}

Player::~Player()
{
}

void Player::update(){
    translate(glm::vec2(0.002f, 0.0f));
    rotate(1.0f);
}
