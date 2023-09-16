#include "Button.h"

Button::Button(int x_, int y_, int w_, int h_) {
    x = x_;
    y = y_;
    w = w_;
    h = h_;
    rect.setSize(sf::Vector2f(w, h));
    rect.setPosition(x, y);
    font.loadFromFile("fonts/sunday.ttf");
    label.setString(L"");
    label.setOutlineColor(sf::Color(180, 180, 180));
    label.setOutlineThickness(0.9);
    label.setFont(font);
    label.setPosition(x + rect.getSize().x / 2 - label.getGlobalBounds().width / 2, y + rect.getSize().y / 2 - label.getGlobalBounds().height / 2);
    label.setFillColor(sf::Color::Black);
    label.setCharacterSize(20);
}

bool Button::isPressed(int x, int y) {
    if (rect.getGlobalBounds().contains(x, y)) {
        return true;
    }
    return false;
}

void Button::setText(std::wstring text) {
    label.setString(text);
}

void Button::setSize(int w_, int h_) {
    w = w_;
    h = h_;
    rect.setSize(sf::Vector2f(w_, h_));
}

void Button::setPosition(int x_, int y_) {
    x = x_;
    y = y_;
    rect.setPosition(x_, y_);
    label.move(x + btnImage.getTextureRect().width * 1.2 - label.getGlobalBounds().width/2, y + btnImage.getTextureRect().height * 0.2);
    btnImage.setPosition(x, y);
}

void Button::draw(sf::RenderWindow& window) {
    btnImage.setTextureRect(sf::IntRect(img_x, img_y, w, h));
    window.draw(btnImage);
    window.draw(label);
}

void Button::setCharacterSize(int dp) {
    label.setCharacterSize(dp);
}

void Button::setImage(std::string path, int x_, int y_) {
    img_x = x_;
    img_y = y_;
    t.loadFromFile(path);
    btnImage.setTexture(t);
    btnImage.setTextureRect(sf::IntRect(img_x, img_y, w, h));
}