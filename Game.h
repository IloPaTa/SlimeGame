#pragma once
#include <SFML/Graphics.hpp>
#include "Enemy.h"
class Game {
public:
    int localW, localH;
    std::wstring run(sf::RenderWindow &window);
    Game(int localW, int localH);
private:
    int now_record = 0;
    std::vector<Enemy> enemies;
    std::vector<Enemy> dead_enemies;
    std::wstring to_string(int x);
};

