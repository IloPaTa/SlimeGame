#pragma once
#include"SFML/Graphics.hpp"
#include "Button.h";
class EndgameMonitor {
public:
    EndgameMonitor(int W_, int H_, std::wstring score_);
    void run(sf::RenderWindow &window);
private:
    int W, H;
    sf::Text gameOverText;
    sf::Text score;
    Button back;
    sf::Font font;
};

