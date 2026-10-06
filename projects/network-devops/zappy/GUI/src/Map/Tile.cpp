/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Tile.cpp
*/

#include "../../include/Tile.hpp"

Tile::Tile()
{
    _type = 0;
    _pos = sf::Vector2f(0, 0);
    _size = sf::Vector2f(50, 50);
    _color = sf::Color::White;
}

Tile::Tile(int type, sf::Vector2f pos, sf::Vector2f size, sf::Color color)
{
    _type = type;
    _pos = pos;
    _size = size;
    _color = color;
}

Tile::~Tile()
{
}

void Tile::setTexture(std::string path)
{
    _texture.loadFromFile(path);
}

void Tile::setSprite()
{
    _sprite.setTexture(_texture);
}

void Tile::setPos(sf::Vector2f pos)
{
    _pos = pos;
}

void Tile::setPos(float x, float y)
{
    _pos = sf::Vector2f(x, y);
}

void Tile::setSize(sf::Vector2f size)
{
    _size = size;
}

void Tile::setSize(float x, float y)
{
    _size = sf::Vector2f(x, y);
}

void Tile::setColor(sf::Color color)
{
    _color = color;
}

void Tile::setType(int type)
{
    _type = type;
}

std::map<std::string, Item> Tile::getItems()
{
    return _items;
}

void Tile::setItem(std::string name, Item item)
{
    _items[name] = item;
}

Item Tile::getItem(std::string resource)
{
    return _items[resource];
}

void Tile::dropItem(std::string item)
{
    _items.erase(item);
}

sf::Vector2f Tile::getPos()
{
    return _pos;
}

sf::Vector2f Tile::getSize()
{
    return _size;
}

sf::Color Tile::getColor()
{
    return _color;
}

int Tile::getType()
{
    return _type;
}

sf::Sprite Tile::getSprite()
{
    return _sprite;
}

sf::Texture Tile::getTexture()
{
    return _texture;
}
