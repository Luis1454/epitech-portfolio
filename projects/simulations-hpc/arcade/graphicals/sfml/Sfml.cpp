/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** sfml
*/

#include "include/Sfml.hpp"

extern "C" IDisplayModule *entryPoint()
{
    return new Sfml();
}

Sfml::Sfml()
{
    _key = 0;
    _lastKey = 0;
}

Sfml::~Sfml()
{
    _window.close();
}

void Sfml::setWindow()
{
    _window.create(sf::VideoMode(1920, 1080), "SFML", sf::Style::Close);
    _window.setFramerateLimit(60);
}

int Sfml::is_lib()
{
    return 1;
}

void Sfml::drawWindow()
{
    _window.display();
}

void Sfml::clear()
{
    _window.clear();
}

sf::Color Sfml::getColor(Color color)
{
    switch (color) {
        case COLOR_Red:
            return sf::Color::Red;
        case COLOR_Green:
            return sf::Color::Green;
        case COLOR_Blue:
            return sf::Color::Blue;
        case COLOR_Yellow:
            return sf::Color::Yellow;
        case COLOR_White:
            return sf::Color::White;
        case COLOR_Black:
            return sf::Color::Black;
        case COLOR_Orange:
            return sf::Color(255, 165, 0);
        case COLOR_Pink:
            return sf::Color::Magenta;
        case COLOR_Purple:
            return sf::Color::Magenta;
        case COLOR_Cyan:
            return sf::Color::Cyan;
        case COLOR_Brown:
            return sf::Color(165, 42, 42);
        case COLOR_Grey:
            return sf::Color(127, 127, 127);
        case COLOR_LightBlue:
            return sf::Color(173, 216, 230);
        case COLOR_AlphaBlack:
            return sf::Color(0, 0, 0, 191);
    }
    return sf::Color::White;
}

void Sfml::drawRect(int x, int y, int width, int height, Color color, int mode)
{
    sf::RectangleShape rectangle(sf::Vector2f(width * 24, height * 24));
    sf::Color border = getColor(color);

    if (mode == 1) {
        x += getWidth() / 2 - width / 2;
        y += getHeight() / 2 - height / 2;
    }
    border = border + (sf::Color::White - border) * 0.5;
    rectangle.setPosition(x * 24, y * 24);
    rectangle.setOutlineThickness(1);
    rectangle.setOutlineColor(border);
    rectangle.setFillColor(getColor(color));
    _window.draw(rectangle);
}

void Sfml::drawCircle(int x, int y, int radius, Color color, int mode)
{
    sf::CircleShape circle(radius);

    if (mode == 1) {
        x += getWidth() / 2;
        y += getHeight() / 2;
    }
    circle.setPosition(x, y);
    circle.setFillColor(getColor(color));
    _window.draw(circle);
}

void Sfml::drawText(int x, int y, std::string text, Color color, int mode)
{
    sf::Text sfText;

    sfText.setCharacterSize(24);
    sfText.setFont(_font);
    sfText.setString(text);
    if (mode == 1) {
        sfText.setOrigin(sfText.getLocalBounds().width / 2, sfText.getLocalBounds().height / 2);
        x = getWidth() / 2;
        y += getHeight() / 2;
    }
    sfText.setFillColor(getColor(color));
    sfText.setPosition(x* 24, y * 24);
    _window.draw(sfText);
}

void Sfml::loadFont(std::string path)
{
    _font.loadFromFile(path);
}

int Sfml::pollEvent()
{
    sf::Event event;
    _key = -1;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            _window.close();
            return 1;
        }
        if (event.type == sf::Event::KeyPressed)
            _key = event.key.code;
    }
    return 0;
}

void Sfml::closeWindow()
{
    _window.close();
}

int Sfml::getKeys()
{
    return _key;
}

int Sfml::getWidth()
{
    return (_window.getSize().x) / 24;
}

int Sfml::getHeight()
{
    return (_window.getSize().y) / 24;
}