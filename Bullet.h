#pragma once
#include "AnimationManager.h"

class Bullet {
public:
    double x, y;
    double dx, dy, damage, speed;
    AnimationManager anim;
    Bullet(AnimationManager anim_, double x_, double y_, double damage_);
    Bullet();
    void setBoost(double to_x, double to_y);
    void update(double time);
    bool isCollision(sf::IntRect object);
    int getDamage();
    void setDamage(int damage_);
    sf::IntRect getRect();
};

