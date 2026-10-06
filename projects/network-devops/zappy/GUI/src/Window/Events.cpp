/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Events
*/

#include "../../include/Renderer.hpp"

sf::Event &Renderer::getEvent()
{
    return _event;
}

void Renderer::eventHandler() {
    while (_window.pollEvent(_event)) {
        if (_event.type == sf::Event::Closed)
            _window.close();
        if (_event.type == sf::Event::KeyPressed)
            if (_event.key.code == sf::Keyboard::Escape)
                _window.close();
    }
}

void Renderer::setState(std::string state)
{
    _state = state;
}

std::string Renderer::getState() const
{
    return _state;
}
