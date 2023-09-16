#pragma once
#include <SFML/Graphics.hpp>

class Button {
public:
    Button(int x = 0, int y = 0, int w = 100, int h = 50);
    bool isPressed(int x, int y);
    void setText(std::wstring);
    void setSize(int w_, int h_);
    void setPosition(int x_, int y_);
    //void setColor(int r, int g, int b);
    //void setColor(sf::Color color);
    void setCharacterSize(int dp);
    void setImage(std::string path, int x_, int y_);
    void draw(sf::RenderWindow& window);
private:
    sf::RectangleShape rect;
    int x, y, w, h, img_x, img_y;
    sf::Font font;
    sf::Text label;
    sf::Texture t;
    sf::Sprite btnImage;
};

