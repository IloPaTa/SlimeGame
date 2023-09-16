#pragma once
#include<SFML/Graphics.hpp>
#include "Animation.h"
class AnimationManager {
public:
    std::string currentAnim;
    std::map<std::string, Animation>  animList = {};
    AnimationManager();
    void create(std::string type, sf::Texture& t, int x, int y, int w, int h, int count, double speed, int step);
    void drawAnim(sf::RenderWindow& window, int x=0, int y=0);
    void set(std::string name);
    void flip(bool type=1);
    void tick(double time);
    void pause();
    void play();
    sf::IntRect getRect();
};

