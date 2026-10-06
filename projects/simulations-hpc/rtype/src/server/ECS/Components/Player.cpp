/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Player
*/

#include "Player.hpp"

void Player::info() const
{
    for (auto &elem : _names)
        std::cout << "Player #" << elem.first << " : " << elem.second << std::endl;
}

void Player::dropEntity(int idx) {
    Component::dropEntity(idx);

    _names.erase(idx);
}

void Player::setName(std::size_t idx, const std::string &name)
{
    _names.insert_or_assign(idx, name);
} 

std::string Player::getName(std::size_t idx) const
{
    if (_names.find(idx) != _names.end())
        return _names.at(idx);
    return std::string("");
}

void Player::setScore(std::size_t idx, int score) {
    _scores.insert_or_assign(idx, score);
}

void  Player::addScore(std::size_t idx, int score) {
    int current = getScore(idx);

    setScore(idx, current + score);
}

int Player::getScore(std::size_t idx) const {
    if (_scores.find(idx) != _scores.end())
        return _scores.at(idx);
    return 0;
}

void Player::setNbKills(std::size_t idx, int nbKills) {
    _nbKills.insert_or_assign(idx, nbKills);
}

void Player::addNbKills(std::size_t idx, int nbKills) {
    int current = getNbKills(idx);

    setNbKills(idx, current + nbKills);
}

int Player::getNbKills(std::size_t idx) const {
    if (_nbKills.find(idx) != _nbKills.end())
        return _nbKills.at(idx);
    return 0;
}

void Player::addKill(std::size_t idx) {
    int current = getNbKills(idx);

    setNbKills(idx, current + 1);
}