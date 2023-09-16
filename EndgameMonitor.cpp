#include "EndgameMonitor.h"


EndgameMonitor::EndgameMonitor(int W_, int H_, std::wstring score_) {
    W = W_;
    H = H_;

    int border = 50;
    int btn_x = W / 2 - W / 12;
    int btn_w = 360, btn_h = 115;

    font.loadFromFile("fonts/sunday.ttf");
    score.setFont(font);
    if (score_ == L"")
        score_ = L"0";
    score.setString(L"Вы убили " + score_ + L" слизней");
    score.setCharacterSize(50);
    score.setPosition(W / 2.65, H / 2);
    score.setFillColor(sf::Color::Black);

    gameOverText.setFont(font);
    gameOverText.setString(L"Игра окончена");
    gameOverText.setString(L"Ваша игра окончена");
    gameOverText.setCharacterSize(70);
    gameOverText.setPosition(W / 3.15, H / 3);
    gameOverText.setFillColor(sf::Color::Black);

    back.setImage("images/menuButtons.png", 12, 158);
    back.setText(L"Выход");
    back.setCharacterSize(30);
    back.setPosition(btn_x, H / 2 + W / 14 + 2 * border);
    back.setSize(btn_w, btn_h);
}

void EndgameMonitor::run(sf::RenderWindow &window) {
    setlocale(LC_ALL, "Russian");
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized) {
                W = static_cast<double>(event.size.width);
                H = static_cast<double>(event.size.height);
                sf::Vector2f windowSize = sf::Vector2f(event.size.width, event.size.height);
                window.setView(sf::View(sf::Vector2f(windowSize.x / 2,
                    windowSize.y / 2), sf::Vector2f(windowSize)));
            }

            if (event.type == sf::Event::MouseButtonReleased) {
                if (back.isPressed(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
                    back.setImage("images/menuButtons.png", 12, 158);
                    return;
                }
            }
        }
        if (back.isPressed(sf::Mouse::getPosition(window).x, sf::Mouse::getPosition(window).y)) {
            back.setImage("images/menuButtons.png", 382, 158);
        }
        else {
            back.setImage("images/menuButtons.png", 12, 158);
        }

        window.clear(sf::Color(99, 0, 199));
        back.draw(window);
        window.draw(score);
        window.draw(gameOverText);
        window.display();
    }
}