/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** game
*/

#include "include/Nibbler.hpp"

extern "C" void *entryPoint()
{
    return new Nibbler();
}

Nibbler::Nibbler()
{
    _bountyScore = 1.0;
    _startSpeed = 10.0;
    _state = 0;
    resetClock();
    setPlayer();
}

Nibbler::~Nibbler()
{
}

int Nibbler::is_lib()
{
    return 0;
}

int Nibbler::getScore()
{
    return _score;
}

void Nibbler::setPlace(int x, int y, int value)
{
    _map[x][y] = value;
}

void Nibbler::setScore(int score)
{
    _score = score;
}

void Nibbler::setClock()
{
    auto duration_since_epoch = std::chrono::system_clock::now().time_since_epoch();

    _clock = std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch).count() - _lastTime;
    _delay = 1000.0 / (_startSpeed + _score);
}

void Nibbler::resetClock()
{
    auto duration_since_epoch = std::chrono::system_clock::now().time_since_epoch();
    _lastTime = std::chrono::duration_cast<std::chrono::milliseconds>(duration_since_epoch).count();
}


int Nibbler::move()
{
    int place = 0;
    std::pair<int, int> head = _player[0];

    setClock();
    if (_clock <= _delay)
        return EMPTY;
    resetClock();
    if (_dir == std::make_pair(0, 0))
        return EMPTY;

    bool left = checkCollision(head.first - 1, head.second);
    bool right = checkCollision(head.first + 1, head.second);
    bool up = checkCollision(head.first, head.second - 1);
    bool down = checkCollision(head.first, head.second + 1);

    _dir.first = _dir.first == -1 && left ? 0 : _dir.first;
    _dir.first = _dir.first == 1 && right ? 0 : _dir.first;
    _dir.second = _dir.second == -1 && up ? 0 : _dir.second;
    _dir.second = _dir.second == 1 && down ? 0 : _dir.second;

    if (left + right + up + down == 3) {
        _dir = !up ? std::make_pair(0, -1) : _dir;
        _dir = !down ? std::make_pair(0, 1) : _dir;
        _dir = !left ? std::make_pair(-1, 0) : _dir;
        _dir = !right ? std::make_pair(1, 0) : _dir;
    }
    if (left + right + up + down == 4)
        return WALL;
    if (_dir == std::make_pair(0, 0))
        return EMPTY;
    _player.insert(_player.begin(), std::make_pair(head.first + _dir.first, head.second + _dir.second));
    place = getPlace(head.first + _dir.first, head.second + _dir.second);
    if (place == BOUNTY) {
        _score += _bountyScore;
        _map[_player[0].first][_player[0].second] = EMPTY;
        _map[rand() % _mapSize.first][rand() % _mapSize.second] = BOUNTY;
    } else
        _player.pop_back();
    return EMPTY;
}

void Nibbler::setDir(std::pair<int, int> dir)
{
    _dir = dir;
}

std::vector<std::pair<int, int>> Nibbler::getPlayer()
{
    return _player;
}

int Nibbler::getPlace(int x, int y)
{
    return _map[x][y];
}

int Nibbler::getState()
{
    return _state;
}

void Nibbler::setState(int state)
{
    _state = state;
}

bool Nibbler::checkCollision(int x, int y)
{
    if (x < 0 || x >= _mapSize.first || y < 0 || y >= _mapSize.second)
        return true;
    if (_map[x][y] == WALL)
        return true;
    for (std::size_t i = 1; i < _player.size(); i++)
        if (_player[i].first == x && _player[i].second == y)
            return true;
    return false;
}

std::pair<int, int> Nibbler::getDir()
{
    return _dir;
}

std::vector<std::vector<int>> Nibbler::getMap()
{
    return _map;
}

bool Nibbler::isWon()
{
    return false;
}

bool Nibbler::isLost()
{
    return false;
}

std::vector<shape_t> Nibbler::getShapes()
{
    return _shapes;
}

void Nibbler::clearShapes()
{
    _shapes.clear();
}

void Nibbler::setPlayer()
{
    _mapSize = std::make_pair(16 * 4, 9 * 4);
    _player = std::vector<std::pair<int, int>>(1, std::make_pair(_mapSize.first / 2, _mapSize.second - 5));
    for (int i = 0; i < 3; i++)
        _player.push_back(std::make_pair(_mapSize.first / 2, _mapSize.second - 4 + i));
    _dir = std::make_pair(0, 0);
    _score = 0;
    _map = std::vector<std::vector<int>>(_mapSize.first, std::vector<int>(_mapSize.second, WALL));
    for (int i = 0; i < _mapSize.first; i++)
        for (int j = 0; j < 5; j++)
            _map[i][_mapSize.second - j - 1] = EMPTY;
    _mapSize.second -= 5;

    std::stack<std::pair<int, int>> stack;
    std::pair<int, int> current = std::make_pair(1, 1);
    stack.push(current);

    while (!stack.empty()) {
        std::vector<std::pair<int, int>> neighbors;
        int x = current.first;
        int y = current.second;
        if (x > 1 && _map[x - 2][y] == WALL)
            neighbors.push_back(std::make_pair(x - 2, y));
        if (x < _mapSize.first - 2 && _map[x + 2][y] == WALL)
            neighbors.push_back(std::make_pair(x + 2, y));
        if (y > 1 && _map[x][y - 2] == WALL)
            neighbors.push_back(std::make_pair(x, y - 2));
        if (y < _mapSize.second - 2 && _map[x][y + 2] == WALL)
            neighbors.push_back(std::make_pair(x, y + 2));
        if (!neighbors.empty()) {
            std::pair<int, int> next = neighbors[rand() % neighbors.size()];
            _map[(current.first + next.first) / 2][(current.second + next.second) / 2] = EMPTY;
            _map[next.first][next.second] = EMPTY;
            stack.push(next);
            current = next;
        } else {
            stack.pop();
            if (!stack.empty())
                current = stack.top();
        }
    }
    for (int i = 0; i < _mapSize.first; ++i) {
        _map[i][0] = EMPTY;
        _map[i][_mapSize.second - 1] = EMPTY;
    }
    for (int j = 0; j < _mapSize.second; ++j) {
        _map[0][j] = EMPTY;
        _map[_mapSize.first - 1][j] = EMPTY;
    }
    _map[_player[0].first][_player[0].second] = EMPTY;
    for (int i = 0; i < 100; i++)
        _map[rand() % (_mapSize.first - 2) + 1][rand() % (_mapSize.second - 2) + 1] = BOUNTY;
    _mapSize.second += 5;
}

void Nibbler::loop()
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
            if (_map[i][j] == WALL)
                shape.color = GAME_Black;
            else
                shape.color = _map[i][j] == BOUNTY ? GAME_Green : GAME_White;
            shape.type = SHAPE_RECT;
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
