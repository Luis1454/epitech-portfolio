/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** HealthBar.cpp
*/

#include "LifeBar.hpp"

void LifeBar::draw(sf::RenderWindow &window)
{
    for (const auto &[id, lifeBar] : _lifeBars)
        if (lifeBar != nullptr && getEntity(id) != nullptr)
            lifeBar->draw(window);
}

void LifeBar::info() const
{
    std::cout << "LifeBar (" << _lifeBars.size() << ")" << std::endl;
    for (auto &lifeBars : _lifeBars)
        std::cout << " - " << lifeBars.first << " : "
        << lifeBars.second->getHealth() << "/"
        << lifeBars.second->getMaxHealth() << std::endl;
}

void LifeBar::dropEntity(int id) {
    Component::dropEntity(id);

    _lifeBars.erase(id);
}

void LifeBar::removeLifeBar(std::size_t id)
{
    _lifeBars.erase(id);
}

void LifeBar::addLifeBar(std::size_t id, std::shared_ptr<HealthBar> lifeBar)
{
    _lifeBars[id] = lifeBar;
}

void LifeBar::setLifeBar(std::size_t id, float life)
{
    if (_lifeBars.find(id) == _lifeBars.end())
        return;
    if (_lifeBars.at(id) != nullptr)
        _lifeBars.at(id)->setHealth(life);
}

void LifeBar::setMaxLife(std::size_t id, float maxLife)
{
    if (_lifeBars.find(id) == _lifeBars.end())
        return;
    if (_lifeBars.at(id) != nullptr)
        _lifeBars.at(id)->setMaxHealth(maxLife);
}

void LifeBar::setMinLife(std::size_t id, float minLife)
{
    if (_lifeBars.find(id) == _lifeBars.end())
        return;
    if (_lifeBars.at(id) != nullptr)
        _lifeBars.at(id)->setMinHealth(minLife);
}


void LifeBar::setPosition(std::size_t id, sf::Vector2f position)

{
    if (_lifeBars.find(id) == _lifeBars.end())
        return;
    if (_lifeBars.at(id) != nullptr)
        _lifeBars.at(id)->setPosition(position);
}
