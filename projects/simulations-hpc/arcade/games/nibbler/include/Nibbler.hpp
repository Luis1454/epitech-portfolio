/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** Nibbler
*/

#ifndef NIBBLER_HPP_
    #define NIBBLER_HPP_

#include "../../IGame.hpp"
#include <stack>

class Nibbler : public IGame
{
    public:
        Nibbler();
        ~Nibbler();
        int is_lib() override;
        void setPlayer() override;
        void setPlace(int x, int y, int value) override;
        void setScore(int score) override;
        void setState(int state) override;
        int move() override;
        void setDir(std::pair<int, int> dir) override;

        std::vector<std::pair<int, int>> getPlayer() override;
        int getPlace(int x, int y) override;
        int getScore() override;
        int getState() override;
        bool checkCollision(int x, int y) override;
        std::pair<int, int> getDir() override;

        std::vector<std::vector<int>> getMap() override;

        bool isWon() override;
        bool isLost() override;

        std::vector<shape_t> getShapes() override;
        void loop() override;
        void resetClock() override;
        void setClock() override;
        void clearShapes() override;

    private:
        std::vector<shape_t> _shapes;
        std::pair<int, int> _dir;
        std::pair<int, int> _mapSize;
        std::vector<std::vector<int>> _map;
        std::vector<std::pair<int, int>> _player;
        int _score;
        int _state;
        int _bountyScore;
        double _lastTime;
        double _startSpeed;
        double _delay;
        double _clock;
};

#endif /* NIBBLER_HPP_ */
