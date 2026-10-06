/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Level
*/

#include "Level.hpp"

Level::Level()
{
    _name = "default";
    _nbEnemies = 100;
    _enemyHP = 100;
    _enemySpeed = 5;
    _bossHP = 3000;
    _killedEnemies = 0;
    _levelDuration = 30;
    _transitionDuration = 5;
}

Level::Level(std::string name, std::size_t nbEnemies, std::size_t enemyHP, std::size_t enemySpeed, std::size_t bossHP) {
    _name = name;
    _nbEnemies = nbEnemies;
    _enemyHP = enemyHP;
    _enemySpeed = enemySpeed;
    _bossHP = bossHP;
    _killedEnemies = 0;
}

Level::Level(std::string name, std::size_t nbEnemies, std::size_t enemyHP, std::size_t enemySpeed,
std::size_t bossHP, float levelDuration, float transitionDuration)
{
    _name = name;
    _nbEnemies = nbEnemies;
    _enemyHP = enemyHP;
    _enemySpeed = enemySpeed;
    _bossHP = bossHP;
    _killedEnemies = 0;
    _levelDuration = levelDuration;
    _transitionDuration = transitionDuration;
}

Level::~Level() {}

void Level::setName(std::string name) {
    _name = name;
}

void Level::setNbEnemies(std::size_t nbEnemies) {
    _nbEnemies = nbEnemies;
}

void Level::setEnemyHP(std::size_t enemyHP) {
    _enemyHP = enemyHP;
}

void Level::setEnemySpeed(std::size_t enemySpeed) {
    _enemySpeed = enemySpeed;
}

void Level::setBossHP(std::size_t bossHP) {
    _bossHP = bossHP;
}

void Level::setKilledEnemies(std::size_t killedEnemies) {
    _killedEnemies = killedEnemies;
}

void Level::killEnemy() {
    _killedEnemies++;
}

std::string Level::getName() const {
    return _name;
}

std::size_t Level::getNbEnemies() const {
    return _nbEnemies;
}

std::size_t Level::getEnemyHP() const {
    return _enemyHP;
}

std::size_t Level::getEnemySpeed() const {
    return _enemySpeed;
}

std::size_t Level::getBossHP() const {
    return _bossHP;
}

std::size_t Level::getKilledEnemies() const {
    return _killedEnemies;
}

void Level::setTransitionDuration(float duration) {
    _transitionDuration = duration;
}

void Level::setLevelDuration(float duration) {
    _levelDuration = duration;
}

float Level::getTransitionDuration() const {
    return _transitionDuration;
}

float Level::getLevelDuration() const {
    return _levelDuration;
}

bool Level::isFinished() const {
    return _killedEnemies == _nbEnemies;
}
