#ifndef PLAYER_HPP
#define PLAYER_HPP
#include"myEngine/Entity.hpp"
#include <iostream>


class Player : public Entity
{
private:

public:
    Player();
    ~Player();
    void update();
};

#endif

