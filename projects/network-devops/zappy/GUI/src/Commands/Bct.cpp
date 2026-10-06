/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Bct.cpp
*/

#include "../../include/Resources/Resource.hpp"
#include "../../include/Commands/Bct.hpp"

Bct::Bct()
{
}

Bct::~Bct()
{
}

void Bct::execute(Renderer &gui)
{
    Tile tile;

    if (getArgs().size() != 9)
        return;
    int x = std::stoi(getArgs().at(0));
    int y = std::stoi(getArgs().at(1));

    tile.setPos(sf::Vector2f(x, y));
    tile.setColor(sf::Color::Green);

    tile.setItem("food", Item(gui.getMap("default").getResource("food"), std::stoi(getArgs().at(2))));
    tile.setItem("linemate", Item(gui.getMap("default").getResource("linemate"), std::stoi(getArgs().at(3))));
    tile.setItem("deraumere", Item(gui.getMap("default").getResource("deraumere"), std::stoi(getArgs().at(4))));
    tile.setItem("sibur", Item(gui.getMap("default").getResource("sibur"), std::stoi(getArgs().at(5))));
    tile.setItem("mendiane", Item(gui.getMap("default").getResource("mendiane"), std::stoi(getArgs().at(6))));
    tile.setItem("phiras", Item(gui.getMap("default").getResource("phiras"), std::stoi(getArgs().at(7))));
    tile.setItem("thystame", Item(gui.getMap("default").getResource("thystame"), std::stoi(getArgs().at(8))));

    gui.getMap("default").setTile(tile);
}
