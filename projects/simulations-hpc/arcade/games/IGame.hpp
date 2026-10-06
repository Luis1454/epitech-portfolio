/*
** EPITECH PROJECT, 2023
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** IGame.hpp
*/

#ifndef IGame_HPP_
    #define IGame_HPP_

#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>
#include <memory>
#include <map>
#include <chrono>

enum Obj {
    EMPTY,
    PLAYER,
    WALL,
    ENEMY,
    BOUNTY,
    OUT
};

enum shapes {
    SHAPE_RECT,
    SHAPE_CIRCLE,
    SHAPE_TRIANGLE,
    SHAPE_LINE,
    SHAPE_TEXT
};

enum mode {
    TOP_LEFT_ALIGN,
    CENTERED
};

enum gameColor {
    GAME_Red,
    GAME_Green,
    GAME_Blue,
    GAME_Yellow,
    GAME_White,
    GAME_Black,
    GAME_Orange,
    GAME_Pink,
    GAME_Purple,
    GAME_Cyan,
    GAME_Brown,
    GAME_Grey,
    GAME_LightBlue
};

typedef struct shape_s {
    int x;
    int y;
    int width;
    int height;
    int value;
    int type;
    int color;
    std::string text;
    int mode;
} shape_t;

class IGame {
    public:
        virtual int is_lib() = 0;
        virtual void setPlayer() = 0;
        virtual void setPlace(int x, int y, int value) = 0;
        virtual void setScore(int score) = 0;
        virtual void setState(int state) = 0;
        virtual int move() = 0;
        virtual void setDir(std::pair<int, int> dir) = 0;

        virtual std::vector<std::pair<int, int>> getPlayer() = 0;
        virtual int getPlace(int x, int y) = 0;
        virtual int getScore() = 0;
        virtual int getState() = 0;
        virtual bool checkCollision(int x, int y) = 0;
        virtual std::pair<int, int> getDir() = 0;
        virtual std::vector<std::vector<int>> getMap() = 0;

        virtual bool isWon() = 0;
        virtual bool isLost() = 0;

        virtual void loop() = 0;
        virtual std::vector<shape_t> getShapes() = 0;
        virtual void setClock() = 0;
        virtual void resetClock() = 0;
        virtual void clearShapes() = 0;

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

#endif /* IGame_HPP_ */
