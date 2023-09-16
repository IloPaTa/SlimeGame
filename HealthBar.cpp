#include "HealthBar.h"

HealthBar::HealthBar() {
    now.setFillColor(sf::Color::Red);
    all.setFillColor(sf::Color::White);
    all.setOutlineThickness(2);
}

void HealthBar::draw(sf::RenderWindow &window) {
    window.draw(all);
    window.draw(now);
}

void HealthBar::changeHealth(double hp) {
    double k = hp / all_hp;
    now.setSize(sf::Vector2f(w * k, h));
    tmp -= 10;
}

void HealthBar::setPosition(double x_, double y_) {
    x = x_;
    y = y_;
    now.setPosition(x, y);
    all.setPosition(x, y);
}
void HealthBar::setSize(double w_, double h_) {
    w = w_;
    h = h_;
    tmp = w;
    now.setSize(sf::Vector2f(w, h));
    all.setSize(sf::Vector2f(w, h));
}
void HealthBar::setHp(int hp) {
    all_hp = hp;
}