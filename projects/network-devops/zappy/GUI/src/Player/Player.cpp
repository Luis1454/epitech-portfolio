/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Player.cpp
*/

#include "../../include/Player.hpp"

Player::Player()
{
}   

Player::Player(int id, int level, int orientation, std::shared_ptr<Team> team, sf::Vector2f position)
{
    _id = id;
    _level = level;
    _orientation = orientation;
    _team = team;
    _position = position;
}

Player::~Player()
{
}

void Player::setId(int id)
{
    _id = id;
}

void Player::setInventory(Inventory inventory)
{
    _inventory = inventory;
}

void Player::setPosition(sf::Vector2f position)
{
    _position = position;
}

void Player::setOrientation(int orientation)
{
    _orientation = orientation;
}

void Player::setLevel(int level)
{
    _level = level;
}

int Player::getId()
{
    return _id;
}

int Player::getLevel()
{
    return _level;
}

int Player::getOrientation()
{
    return _orientation;
}

std::shared_ptr<Team> Player::getTeam()
{
    return _team;
}

void Player::setTeam(std::shared_ptr<Team> team)
{
    _team = team;
}

sf::Vector2f Player::getPosition()
{
    return _position;
}

Inventory Player::getInventory()
{
    return _inventory;
}
