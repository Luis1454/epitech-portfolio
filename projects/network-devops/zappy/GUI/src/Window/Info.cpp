/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Info
*/

#include "../../include/Info.hpp"

Info::Info()
{
    sf::Font font;

    _text.setString("");
    _text.setCharacterSize(16);
    _text.setPosition(sf::Vector2f(0, 0));
    _text.setFont(font);
}

Info::Info(std::string info, sf::Vector2f pos)
{
    sf::Font font;


    _text.setString(info);
    _text.setCharacterSize(16);
    _text.setPosition(pos);
    _text.setFont(font);
}

Info::Info(std::string info, sf::Vector2f pos, sf::Text text)
{
    _text = text;
    _text.setString(info);
    _text.setPosition(pos);
}

Info::~Info()
{
}

void Info::setInfo(std::string info)
{
    _text.setString(info);
}

std::string Info::getInfo() const
{
    return _text.getString();
}

void Info::setPos(sf::Vector2f pos)
{
    _text.setPosition(pos);
}

sf::Vector2f Info::getPos() const
{
    return _text.getPosition();
}

void Info::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    (void)states;
    target.draw(_text, states);
}

void Info::setStyle(sf::Text text)
{
    _text = text;
}

sf::Text Info::getStyle() const
{
    return _text;
}
