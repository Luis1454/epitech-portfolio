/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pin.cpp
*/

#include "../../include/Inventory.hpp"
#include "../../include/Commands/Pin.hpp"

Pin::Pin()
{
}

Pin::~Pin()
{
}

void Pin::execute(Renderer &gui)
{
    if (getArgs().size() != 10)
        return;
    int id = std::stoi(getArgs().at(0));
    int x = std::stoi(getArgs().at(1));
    int y = std::stoi(getArgs().at(2));
    int food = std::stoi(getArgs().at(3));
    int linemate = std::stoi(getArgs().at(4));
    int deraumere = std::stoi(getArgs().at(5));
    int sibur = std::stoi(getArgs().at(6));
    int mendiane = std::stoi(getArgs().at(7));
    int phiras = std::stoi(getArgs().at(8));
    int thystame = std::stoi(getArgs().at(9));

    Inventory inv;

    inv.setItem(gui.getMap("default").getResource("food"), food);
    inv.setItem(gui.getMap("default").getResource("linemate"), linemate);
    inv.setItem(gui.getMap("default").getResource("deraumere"), deraumere);
    inv.setItem(gui.getMap("default").getResource("sibur"), sibur);
    inv.setItem(gui.getMap("default").getResource("mendiane"), mendiane);
    inv.setItem(gui.getMap("default").getResource("phiras"), phiras);
    inv.setItem(gui.getMap("default").getResource("thystame"), thystame);
    gui.getMap("default").getPlayer(id).setInventory(inv);
    gui.getMap("default").getPlayer(id).setPosition(sf::Vector2f(x, y));

    std::vector<std::string> items = {
        "food",
        "linemate",
        "deraumere",
        "sibur",
        "mendiane",
        "phiras",
        "thystame"
    };
}
