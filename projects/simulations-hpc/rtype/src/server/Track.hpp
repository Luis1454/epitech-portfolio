/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Track
*/

#ifndef TRACK_HPP_
#define TRACK_HPP_

#include "Level.hpp"
#include <vector>

class Track {
    public:
        Track();
        ~Track();

        Level &getLevel(std::string name);
        Level &getLevel(std::size_t idx);

        std::vector<Level> getLevels() const;

        std::size_t getCurrentLevel() const;

        void addLevel(Level level);
        void dropLevel(std::size_t idx);
        void setCurrentLevel(std::size_t currentLevel);
        void nextLevel();

        void reset();

        bool isFinished() const;

    private:
        std::vector<Level> _levels;
        std::size_t _currentLevel;
};

#endif /* !TRACK_HPP_ */
