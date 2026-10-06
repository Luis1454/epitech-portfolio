/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Resource
*/

#ifndef RESOURCE_HPP_
#define RESOURCE_HPP_

#include <SFML/Graphics.hpp>

class Resource {
    public:
        Resource();
        ~Resource();

        std::string getName();

        void setSprite(sf::Texture &texture, sf::IntRect rect);
        void setSprite(sf::Texture &texture);
        sf::Sprite &getSprite();

        void setOffset(sf::Vector2f offset);
        void setOffset(double x, double y);
        sf::Vector2f getOffset();

    protected:
        int _id;

        std::string _name;
        sf::Sprite _sprite;
        sf::Vector2f _offset;
        sf::Vector2f _resize;
        sf::Vector2f _spriteSize;
        sf::Vector2f _spriteCoord;
};

#endif /* !RESOURCE_HPP_ */
