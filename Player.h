#pragma once
#include "AnimationManager.h"
#include "Level.h"
#include <string>
#include <vector>
#include <map>
#include <SFML/Graphics.hpp>
#include "Bullet.h"
#include "Enemy.h"
#include "HealthBar.h"

class Player {
public:
    int dir, up;
    double x, y, dx, dy, w, h, last_x, last_y;
    AnimationManager anim;
    AnimationManager bullet_anim;
    enum {stay, walk, climb_up, climb_down} STATE;
    std::map<std::string, bool> key;
    
    Player(AnimationManager& a);

    void KeyCheck();

    void update(double time, std::vector<Object> a, std::vector<Enemy> &e);

    void draw(sf::RenderWindow& window);

    bool isCollision(std::vector<Object> a);

    bool crash(sf::IntRect enemy);

    void shoot(int x, int y);

    void setBulletAnim(AnimationManager anim);

    void getDamage(int damage);

    void setHp(int hp_);
    bool isDead();
    sf::IntRect getRect();

private:
    int hp;
    HealthBar hpBar;
    std::vector<Bullet> bullets;
};

