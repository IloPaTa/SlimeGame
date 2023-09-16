#include "Bullet.h"
#include <iostream>
#include <cmath>

Bullet::Bullet(AnimationManager anim_, double x_, double y_, double damage_) {
    x = x_;
    y = y_;
    damage = damage_;
    anim = anim_;
    speed = 0.2;
}

Bullet::Bullet() {

}

void Bullet::setBoost(double to_x, double to_y) {

    double a = abs(to_x - x);
    double b = abs(to_y - y);
    double gip = sqrt(a * a + b * b);
    dx = speed * a / gip;
    dy = speed * b / gip;
    if (to_x - x < 0)
        dx = -dx;
    if (to_y - y < 0)
        dy = -dy;
}

void Bullet::update(double time) {
    x = x + dx * time;
    y = y +  dy * time;
    anim.tick(time);
}

int Bullet::getDamage() {
    return damage;
}

sf::IntRect Bullet::getRect() {
    sf::IntRect tmp = anim.getRect();
    tmp.left = x;
    tmp.top = y;
    return tmp;
}

bool Bullet::isCollision(sf::IntRect object) {
    object.top += 70;
    if (object.intersects(getRect())) {
        return true;
    }
    return false;
}

void Bullet::setDamage(int damage_) {
    damage = damage_;
}
