#pragma once
#include "Button.h"
class Menu {
public:
    Menu(){}
    Menu(int w, int h);
    void run();
private:
    int to_int(std::string a);
    int W, H, pred_record;
    Button startGame, settings, exit;
    sf::Font font;
    sf::Text title;
    sf::Text record;
    std::wstring score;
};

