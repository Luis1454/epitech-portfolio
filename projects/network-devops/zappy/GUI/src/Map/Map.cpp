/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Map
*/

#include "../../include/Map.hpp"

#include "../../include/Resources/Food.hpp"
#include "../../include/Resources/Sibur.hpp"
#include "../../include/Resources/Phiras.hpp"
#include "../../include/Resources/Mendiane.hpp"
#include "../../include/Resources/Linemate.hpp"
#include "../../include/Resources/Thystame.hpp"
#include "../../include/Resources/Deraumere.hpp"
 

/**
 * @brief Initialize the Map object
 */
Map::Map()
{
    _pos = std::pair<int, int>(0, 0);
    _size = std::pair<int, int>(1920, 1080);

    updateShape();

    _resources["food"] = std::make_shared<Food>();
    _resources["sibur"] = std::make_shared<Sibur>();
    _resources["phiras"] = std::make_shared<Phiras>();
    _resources["mendiane"] = std::make_shared<Mendiane>();
    _resources["thystame"] = std::make_shared<Thystame>();
    _resources["linemate"] = std::make_shared<Linemate>();
    _resources["deraumere"] = std::make_shared<Deraumere>();
}

/**
 * @brief Destroy the Map object
 */
Map::~Map()
{
}

/**
 * @brief Update the shape of the map
 * 
 * @param tile
 */
void Map::updateShape()
{
    _shape = std::pair<int, int>(0, 0);
    for (auto &tile : _tiles) {
        if (tile.second.getPos().x + 1 > _shape.first)
            _shape.first = tile.second.getPos().x + 1;
        if (tile.second.getPos().y + 1> _shape.second)
            _shape.second = tile.second.getPos().y + 1;
    }
    _tileSize = {
        _shape.first ? _size.first / _shape.first : 1,
        _shape.second ? _size.second / _shape.second : 1
    };
}

/**
 * @brief Update the position of the map
 *
 * @param size
 */
void Map::updatePos(sf::Vector2f size)
{
    _pos = {
        (double)(size.x - _shape.first * _tileSize.first) / 2,
        (double)(size.y - _shape.second * _tileSize.second) / 2
    };
}

/**
 * @brief Set the shape of the map
 * 
 * @param gui
 */
void Map::setShape(int x, int y)
{
    _shape = std::pair<int, int>(x, y);
}

/**
 * @brief Get the shape of the map
 * 
 * @return std::pair<double, double>
 */
std::pair<int, int> Map::getShape() const
{
    return _shape;
}

/**
 * @brief Set the size of the map
 *
 * @return std::pair<double, double>
 */
void Map::setSize(double x, double y)
{
    _size = std::pair<double, double>(x, y);
}

/**
 * @brief Set the size of the map
 *
 * @return sf::Vector2f
 */
void Map::setSize(sf::Vector2f size)
{
    _size = std::pair<double, double>(size.x, size.y);
}

/**
 * @brief Get the size of the map
 *
 * @return std::pair<int, int>
 */
std::pair<double, double> Map::getSize() const
{
    return _size;
}

/**
 * @brief Set the position of the map
 * 
 * @param x
 * @param y
 */
void Map::setPos(double x, double y)
{
    _pos = std::pair<double, double>(x, y);
}

/**
 * @brief Get the position of the map
 * 
 * @return std::pair<double, intdouble>
 */
std::pair<double, double> Map::getPos() const
{
    return _pos;
}

/**
 * @brief Get a ressource given its name
 * 
 * @param name name of the resource
 * @return std::shared_ptr<Resource>
 */
std::shared_ptr<Resource> Map::getResource(std::string name)
{
    return _resources[name];
}

/**
 * @brief Get all the resources
 * 
 * @return std::map<std::string, std::shared_ptr<Resource>>
 */
std::map<std::string, std::shared_ptr<Resource>> Map::getResources() const
{
    return _resources;
}