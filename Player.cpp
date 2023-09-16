#include "Player.h"
#include <string>
#include <vector>
#include <map>
#include <cerrno>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <SFML/Graphics.hpp>

Player::Player(AnimationManager& a) {
    anim = a;
    x = 100;
    y = 100;
    hp = 100;
    hpBar.setHp(hp);
    hpBar.setPosition(10, 10);
    hpBar.setSize(200, 40);
    STATE = stay;
}

void Player::KeyCheck() {
    if (key["L"]) {
        dir = 1;
        dx = -0.1;
        STATE = walk;
    }

    if (key["R"]) {
        dir = 0;
        dx = 0.1;
        STATE = walk;
    }

    if (key["D"]) {
        up = 1;
        dy = 0.1;
            STATE = climb_down;
    }

    if (key["U"]) {
        up = 0;
        dy = -0.1;
        STATE = climb_up;
    }

    if (!key["R"] && !key["L"] && !key["D"] && !key["U"] && !key["S"]) {
        dx = 0;
        dy = 0;
        STATE = stay;
    }
}

void Player::draw(sf::RenderWindow& window) {
    anim.drawAnim(window, x, y);
    for (int i = 0; i < bullets.size(); ++i ) {
        bullets[i].anim.drawAnim(window, bullets[i].x, bullets[i].y);
    }
    hpBar.draw(window);
}

void Player::update(double time, std::vector<Object> a, std::vector<Enemy> &e) {
    KeyCheck();

    extern int W;
    extern int H;
    if (STATE == stay)
        anim.set("stay");
    if (STATE == walk)
        anim.set("walk");
    if (STATE == climb_up)
        anim.set("up");
    if (STATE == climb_down)
        anim.set("down");

    if (dir)
        anim.flip();

    anim.tick(time);

    for (int i = 0; i < bullets.size(); ++i) {
        bullets[i].update(time);
    }

    for (int i = 0; i < bullets.size(); ++i) {
        for (int j = 0; j < e.size(); ++j) {
            if (bullets[i].isCollision(e[j].getRect())) {
                e[j].getDamage(bullets[i].damage);
                bullets.erase(bullets.begin() + i);
                --i;
                break;
            }
        }
    }

    for (int i = 0; i < bullets.size(); ++i) {
        for (auto j : a) {
            if (bullets[i].isCollision(j.rect)) {
                bullets.erase(bullets.begin() + i);
                --i;
                break;
            }
        }
    }
    x += dx * time;
    y += dy * time;

    if (isCollision(a)) {
        y = last_y;
        x = last_x;
    }
    else {
        last_x = x;
        last_y = y;
    }
    key["R"] = false;
    key["L"] = false;
    key["D"] = false;
    key["U"] = false;
    key["S"] = false;
    dx = 0;
    dy = 0;
    hpBar.changeHealth(hp);
}

sf::IntRect Player::getRect() {
    sf::IntRect tmp = anim.getRect();
    if (dir == 1)
        tmp.left = x + 40;
    else
        tmp.left = x;
    tmp.top = y - 75;
    return tmp;
}

bool Player::isCollision(std::vector<Object> a){
    for (auto i : a) {
        sf::IntRect tmp = i.rect;
        if (tmp.intersects(getRect())) {
            return true;
        }
    }
    return false;
}

bool Player::crash(sf::IntRect enemy) {
    if (getRect().intersects(enemy)) {
        return true;
    }
    return true;
}

void Player::setBulletAnim(AnimationManager anim) {
    bullet_anim = anim;
}

void Player::shoot(int x_, int y_) {
    Bullet bull(bullet_anim, x, y, 1);
    bull.setBoost(x_, y_);
    bull.setDamage(10);
    bullets.push_back(bull);
}

void Player::getDamage(int damage) {
    hp -= damage;
}

void Player::setHp(int hp_) {
    hp = std::min(hp_ + hp, 100);
}

bool Player::isDead() {
    if (hp <= 0) {
        return true;
    }
    return false;
}