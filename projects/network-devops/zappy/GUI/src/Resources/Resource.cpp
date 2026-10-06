/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Resource
*/

#include "../../include/Resources/Resource.hpp"

Resource::Resource()
{
    _id = -1;
    _name = "unknown";
    _spriteCoord = {0, 0};
    _resize = {0.3, 0.3};
    _spriteSize = {84, 89};
    _offset = {0, 0};
}

Resource::~Resource()
{
}

void Resource::setSprite(sf::Texture &texture, sf::IntRect rect)
{
    _sprite.setTexture(texture);
    _sprite.setTextureRect(rect);
}

void Resource::setSprite(sf::Texture &texture)
{
    sf::IntRect rect = {
        (int)_spriteCoord.x,
        (int)_spriteCoord.y,
        (int)_spriteSize.x,
        (int)_spriteSize.y
    };
    _sprite.setTexture(texture);
    _sprite.setTextureRect(rect);
    _sprite.setScale(_resize);
}

void Resource::setOffset(sf::Vector2f offset)
{
    _offset = offset;
}


void Resource::setOffset(double x, double y)
{
    _offset = sf::Vector2f(x, y);
}

sf::Vector2f Resource::getOffset()
{
    return _offset;
}

sf::Sprite &Resource::getSprite()
{
    return _sprite;
}

std::string Resource::getName()
{
    return _name;
}
