/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Eggs
*/

#include "../../include/Renderer.hpp"
#include "../../include/Egg.hpp"

void Map::setEgg(Egg egg)
{
    _eggs[egg.getId()] = egg;
}

Egg Map::getEgg(int id)
{
    return _eggs[id];
}

void Map::dropEgg(int id)
{
    if (_eggs.find(id) != _eggs.end())
        _eggs.erase(id);
}

void Map::showEggs(Renderer &gui)
{
    sf::Vector2f pos;

    for (auto &egg : _eggs) {
        pos = sf::Vector2f(
            gui.getMap("default").getEgg(egg.first).getPosition().x * _tileSize.first + _pos.first + _tileSize.first * 0.5,
            gui.getMap("default").getEgg(egg.first).getPosition().y * _tileSize.second + _pos.second + _tileSize.second * 0.75
        );
        gui.getMap("default").getEgg(egg.first).getSprite()->setPosition(pos);
        gui.getMap("default").getEgg(egg.first).getSprite()->setOrigin(
            gui.getMap("default").getEgg(egg.first).getSprite()->getLocalBounds().width / 2,
            gui.getMap("default").getEgg(egg.first).getSprite()->getLocalBounds().height / 2
        );
        gui.getMap("default").getEgg(egg.first).getSprite()->setColor(sf::Color(255, 127, 0));
        gui.getMap("default").getEgg(egg.first).getSprite()->setScale(
            sf::Vector2f(
                ((double)_tileSize.first) / egg.second.getSprite()->getLocalBounds().width / 5.0,
                ((double)_tileSize.second) / egg.second.getSprite()->getLocalBounds().height / 5.0
            )
        );
        gui.draw(egg.second);
    }
}

void Renderer::setEggSprite(std::string name, sf::Sprite &sprite)
{
    _eggsSprites[name] = sprite;
}

sf::Sprite &Renderer::getEggSprite(std::string name)
{
    return _eggsSprites[name];
}
