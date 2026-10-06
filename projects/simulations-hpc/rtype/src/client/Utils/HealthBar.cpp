/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** HealthBar
*/

#include "HealthBar.hpp"

HealthBar::HealthBar(int min, int max, int value, sf::Vector2f pos) : _min(min), _max(max)
{
    float ratio = (value - min) / (float)(max - min);

    _value = value;
    _min = min;
    _max = max;

    _border.setSize(sf::Vector2f(100, 10));
    _border.setFillColor(sf::Color::Transparent);
    _border.setPosition(pos);
    _border.setOutlineColor(sf::Color::Red);
    _border.setOutlineThickness(2);
    _border.setOrigin(0, 0);
    _border.setScale(0.5, 0.5);

    _healthBar = _border;

    sf::Color color = ratio > 0.5
    ? sf::Color::Green : ratio > 0.2
    ? sf::Color::Yellow : sf::Color::Red;

    _healthBar.setFillColor(color);
    _healthBar.setSize(sf::Vector2f(ratio * 100, 10));
    _healthBar.setOutlineThickness(0);
}

void HealthBar::draw(sf::RenderWindow &window) const {
    if (!window.isOpen())
        return;
    if (_border.getPointCount() > 0)
        window.draw(_border);
    if (_healthBar.getPointCount() > 0)
        window.draw(_healthBar);
    // sf::Font font;
    // sf::Text text;

    // if (font.loadFromFile("src/client/assets/nasa.otf")) {
    //     text.setFont(font);
    //     text.setString(std::to_string(_value));
    //     text.setCharacterSize(10);
    //     text.setFillColor(sf::Color::White);
    //     text.setPosition(_border.getPosition().x, _border.getPosition().y - 15);
    //     target.draw(text, states);
    // }
}

int HealthBar::getHealth() const
{
    return _value;
}

int HealthBar::getMaxHealth() const
{
    return _max;
}

void HealthBar::setHealth(int value)
{
    float ratio = 0;

    if ((_max - _min) != 0)
        ratio = (value - _min) / (float)(_max - _min);
    _value = value;
    _healthBar.setSize(sf::Vector2f(ratio * 100, 10));
    sf::Color color = ratio > 0.5
    ? sf::Color::Green : ratio > 0.2
    ? sf::Color::Yellow : sf::Color::Red;
    _healthBar.setFillColor(color);
}

void HealthBar::setMaxHealth(int value)
{
    _max = value;
}

void HealthBar::setMinHealth(int value)
{
    _min = value;
}

void HealthBar::setPosition(sf::Vector2f pos)
{
    _border.setPosition(pos);
    _healthBar.setPosition(pos);
}
