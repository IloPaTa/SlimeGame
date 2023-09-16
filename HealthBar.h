#pragma once
#include <SFML/Graphics.hpp>
class HealthBar {
public:
    HealthBar();
    void draw(sf::RenderWindow& window);
    void changeHealth(double hp);
    void setPosition(double x_, double y_);
    void setSize(double w_, double h_);
    void setHp(int hp);
private:
    sf::RectangleShape now, all;
    int all_hp;
    double x, y, w, h, tmp;
};

