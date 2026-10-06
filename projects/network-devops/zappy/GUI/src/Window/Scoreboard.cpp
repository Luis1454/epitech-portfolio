/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Scoreboard
*/

#include "../../include/Scoreboard.hpp"
#include "../../include/Renderer.hpp"

Scoreboard::Scoreboard()
{
}

Scoreboard::~Scoreboard()
{
}

void Scoreboard::setInfo(std::string name, Info info)
{
    _infos[name] = info;
}

std::map<std::string, Info> Scoreboard::getInfos() const
{
    return _infos;
}

void Scoreboard::setBackground(sf::RectangleShape background)
{
    _background = background;
}

sf::RectangleShape &Scoreboard::getBackground()
{
    return _background;
}

void Scoreboard::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    (void)states;

    target.draw(_background);
    for (auto &info : _infos)
        target.draw(info.second);
}

void Renderer::setScoreboard(Scoreboard scoreboard)
{
    _scoreboard = scoreboard;
}

Scoreboard &Renderer::getScoreboard()
{
    return _scoreboard;
}
