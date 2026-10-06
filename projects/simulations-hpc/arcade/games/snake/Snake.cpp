/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** game
*/

#include "include/Snake.hpp"

extern "C" void *entryPoint()
{
    return new Snake();
}

Snake::Snake()
{
    resetClock();
    _bountyScore = 1.0;
    _startSpeed = 10;
    setPlayer();
    _state = 0;
}

Snake::~Snake()
{
}

int Snake::is_lib()
{
    return 0;
}

int Snake::getScore()
{
    return _score;
}

void Snake::setPlayer()
{
    _mapSize = std::make_pair(16 * 4, 9 * 4);
    _player = std::vector<std::pair<int, int>>(1, std::make_pair(_mapSize.first / 2, _mapSize.second / 2));
    for (int i = 0; i < 3; i++)
        _player.push_back(std::make_pair(_player[0].first - i - 1, _player[0].second));
    _shapes.clear();
    _dir = std::make_pair(0, 0);
    _score = 0;
    _map = std::vector<std::vector<int>>(_mapSize.first, std::vector<int>(_mapSize.second, EMPTY));
    _map[rand() % _mapSize.first][rand() % _mapSize.second] = BOUNTY;
}

void Snake::setPlace(int x, int y, int value)
{
    _map[x][y] = value;
}

void Snake::setScore(int score)
{
    _score = score;
}

void Snake::setClock()
{
    auto duration_since_epoch = std::chrono::system_clock::now().time_since_epoch();

    _clock = std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch).count() - _lastTime;
    _delay = 1000.0 / (_startSpeed + _score);
}

void Snake::resetClock()
{
    auto duration_since_epoch = std::chrono::system_clock::now().time_since_epoch();
    _lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch).count();
}

int Snake::move()
{
    int place = 0;
    std::pair<int, int> head = _player[0];

    setClock();
    if (_clock <= _delay)
        return EMPTY;
    resetClock();
    if (head.first < 0 || head.first >= _mapSize.first || head.second < 0 || head.second >= _mapSize.second) {
        _state = -1;
        return WALL;
    }
    if (head.first + _dir.first < 0 || head.first + _dir.first >= _mapSize.first
    || head.second + _dir.second < 0 || head.second + _dir.second >= _mapSize.second)
        return WALL;
    place = getPlace(head.first + _dir.first, head.second + _dir.second);
    if (place != EMPTY && place != BOUNTY)
        return place;
    if (_dir == std::make_pair(0, 0))
        return EMPTY;
    _player.insert(_player.begin(), std::make_pair(head.first + _dir.first, head.second + _dir.second));
    if (place == BOUNTY) {
        _score += _bountyScore;
        _map[_player[0].first][_player[0].second] = EMPTY;
        _map[rand() % _mapSize.first][rand() % _mapSize.second] = BOUNTY;
    } else
        _player.pop_back();
    return EMPTY;
}

void Snake::setDir(std::pair<int, int> dir)
{
    if ((_dir.first == -dir.first || _dir.second == -dir.second) && _dir != std::make_pair(0, 0))
        return;
    _dir = dir;
}

std::vector<std::pair<int, int>> Snake::getPlayer()
{
    return _player;
}

int Snake::getPlace(int x, int y)
{
    return _map[x][y];
}

int Snake::getState()
{
    return _state;
}

void Snake::setState(int state)
{
    _state = state;
}

bool Snake::checkCollision(int x, int y)
{
    if (x < 0 || x >= _mapSize.first || y < 0 || y >= _mapSize.second)
        return true;
    if (_map[x][y] == WALL || _map[x][y] == PLAYER)
        return true;
    for (std::size_t i = 1; i < _player.size(); i++)
        if (_player[i].first == x && _player[i].second == y)
            return true;
    return false;
}

std::pair<int, int> Snake::getDir()
{
    return _dir;
}

std::vector<std::vector<int>> Snake::getMap()
{
    return _map;
}

bool Snake::isWon()
{
    return false;
}

bool Snake::isLost()
{
    return checkCollision(_player[0].first, _player[0].second);
}

std::vector<shape_t> Snake::getShapes()
{
    return _shapes;
}

void Snake::clearShapes()
{
    _shapes.clear();
}

void Snake::loop()
{
    std::vector<int> colors = {GAME_Orange, GAME_Purple};
    std::size_t i = 0;

    _shapes.clear();
    for (int i = 0; i < _mapSize.first; i++) {
        for (int j = 0; j < _mapSize.second; j++) {
            shape_t shape;
            shape.x = i - _mapSize.first / 2;
            shape.y = j - _mapSize.second / 2;
            shape.width = 1;
            shape.height = 1;
            shape.value = _map[i][j];
            shape.type = SHAPE_RECT;
            shape.color = _map[i][j] == BOUNTY ? GAME_Green : GAME_White;
            shape.mode = CENTERED;
            _shapes.push_back(shape);
        }
    }
    for (i = 0; i < _player.size(); i++) {
        shape_t shape;
        shape.x = _player[i].first - _mapSize.first / 2;
        shape.y = _player[i].second - _mapSize.second / 2;
        shape.width = 1;
        shape.height = 1;
        shape.value = PLAYER;
        shape.type = SHAPE_RECT;
        if (i)
            shape.color = colors[((i + 1) / 2) % colors.size()];
        else
            shape.color = GAME_Red;
        shape.mode = CENTERED;
        _shapes.push_back(shape);
    }
}
