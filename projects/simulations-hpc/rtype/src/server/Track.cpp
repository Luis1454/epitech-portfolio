/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Track
*/

#include "Track.hpp"

Track::Track() {
    _levels.push_back(Level("Level 1", 10, 100, 5, 1000, 30, 5));
    _levels.push_back(Level("Level 2", 25, 125, 6, 1500, 40, 5));
    _levels.push_back(Level("Level 3", 50, 150, 7, 2500, 50, 5));
    // _levels.push_back(Level("Level 4", 100, 175, 9, 3750, 60, 5));
    // _levels.push_back(Level("Level 5", 200, 200, 12, 5000, 70, 7));
    // _levels.push_back(Level("Level 6", 300, 225, 15, 6250, 80, 7));
    // _levels.push_back(Level("Level 7", 400, 250, 18, 7500, 90, 7));
    // _levels.push_back(Level("Level 8", 500, 275, 21, 8750, 100, 7));
    // _levels.push_back(Level("Level 9", 600, 300, 24, 10000, 110, 7));
    // _levels.push_back(Level("Level 10", 700, 325, 27, 11250, 120, 7));
    _currentLevel = 0;
}

Track::~Track() {
    _levels.clear();
    _currentLevel = 0;
}

Level &Track::getLevel(std::string name) {
    for (auto &level : _levels)
        if (level.getName() == name)
            return level;
    return _levels.front();
}

Level &Track::getLevel(std::size_t idx) {
    if (idx >= _levels.size())
        return _levels.front();
    return _levels.at(idx);
}

std::vector<Level> Track::getLevels() const {
    return _levels;
}

std::size_t Track::getCurrentLevel() const {
    return _currentLevel;
}

void Track::addLevel(Level level) {
    _levels.push_back(level);
}

void Track::dropLevel(std::size_t idx) {
    _levels.erase(_levels.begin() + idx);
}

void Track::setCurrentLevel(std::size_t currentLevel) {
    _currentLevel = currentLevel;
}

void Track::nextLevel() {
    _currentLevel++;
}

void Track::reset() {
    _currentLevel = 0;
}

bool Track::isFinished() const {
    return _currentLevel >= _levels.size();
}
