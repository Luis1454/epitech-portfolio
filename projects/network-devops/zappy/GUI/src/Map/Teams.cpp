/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Teams
*/

#include "../../include/Map.hpp"

void Map::setTeam(std::string name)
{
    int i = 0;

    for (auto &team : _teams) {
        if (team.first == name)
            break;
        i++;
    }
    _teams[name] = std::make_shared<Team>(i, name);
}

void Map::dropTeam(std::string name)
{
    if (_teams.find(name) != _teams.end())
        _teams.erase(name);
}

std::vector<std::shared_ptr<Team>> Map::getTeams() const
{
    std::vector<std::shared_ptr<Team>> teams;

    for (auto &team : _teams)
        teams.push_back(team.second);
    return teams;
}

std::shared_ptr<Team> Map::getTeam(std::string name)
{
    if (_teams.find(name) != _teams.end())
        return _teams[name];
    return nullptr;
}
