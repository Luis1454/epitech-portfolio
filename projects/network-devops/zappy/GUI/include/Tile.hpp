/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Tile.hpp
*/

#ifndef TILE_HPP_
#define TILE_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include "Item.hpp"

class Tile {
    public:
        Tile();
        Tile(int type, sf::Vector2f pos, sf::Vector2f size, sf::Color color);
        ~Tile();

        void setTexture(std::string path);
        void setSprite();
        void setPos(sf::Vector2f pos);
        void setPos(float x, float y);
        void setSize(sf::Vector2f size);
        void setSize(float x, float y);
        void setColor(sf::Color color);
        void setType(int type);
        std::map<std::string, Item> getItems();
        Item getItem(std::string name);
        void setItem(std::string name, Item item);
        void dropItem(std::string name);

        int getType();

        sf::Vector2f getPos();
        sf::Vector2f getSize();
        sf::Color getColor();
        sf::Sprite getSprite();
        sf::Texture getTexture();

    private:
        int _type;
        std::map<std::string, Item> _items;
        sf::Vector2f _pos;
        sf::Vector2f _size;
        sf::Color _color;
        sf::Texture _texture;
        sf::Sprite _sprite;
};

#endif /* !TILE_HPP_ */