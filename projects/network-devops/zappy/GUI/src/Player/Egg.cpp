/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Egg.cpp
*/

#include "../../include/Egg.hpp"

/**
 * @brief Construct a new Egg:: Egg object
 * 
 */
Egg::Egg()
{
}

/**
 * @brief Construct a new Egg:: Egg object
 * 
 * @param eggId Id of the egg
 * @param playerId Id of the player
 * @param pos Position of the egg
 */
Egg::Egg(int eggId, int playerId, sf::Vector2i pos, std::shared_ptr<sf::Sprite> sprite)
{
    _id = eggId;
    _playerId = playerId;
    _position = pos;
    _sprite = sprite;
    _spriteSize = {0.1, 0.1};
}

/**
 * @brief Construct a new Egg:: Egg object
 * 
 * @param id Id of the egg
 */
Egg::Egg(int id)
{
    _id = id;
}

/**
 * @brief Destroy the Egg:: Egg object
 * 
 */
Egg::~Egg()
{
}

/**
 * @brief Get the Id object
 * 
 * @return int Id of the egg
 */
int Egg::getId() const
{
    return _id;
}

/**
 * @brief Set the Id object
 * 
 * @param id Id of the egg
 */
void Egg::setId(int id)
{
    _id = id;
}

/**
 * @brief Draw the egg
 * 
 * @param target
 * @param states
 */
void Egg::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    if (_sprite != nullptr)
        target.draw(*_sprite, states);
}

/**
 * @brief Get the Position object
 * 
 */
sf::Vector2i Egg::getPosition()
{
    return _position;
}

/**
 * @brief Set the Position object
 * 
 */
void Egg::setPosition(sf::Vector2i pos)
{
    _position = pos;
}

/**
 * @brief Get the Sprite object
 * 
 */
std::shared_ptr<sf::Sprite> Egg::getSprite()
{
    return _sprite;
}

/**
 * @brief Set the Sprite object
 * 
 */
void Egg::setSprite(std::shared_ptr<sf::Sprite> sprite)
{
    _sprite = sprite;
}
