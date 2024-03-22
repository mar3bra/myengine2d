#ifndef ENEMY_HPP
#define ENEMY_HPP
#include "myEngine/Entity.hpp"
#include <iostream>
class Enemy : public Entity
{
private:

public:
    Enemy();
    ~Enemy();

    void update();
};

#endif

