/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Window
*/

#include "../../include/Renderer.hpp"

/**
 * @brief Initialize the window
 */
void Renderer::initWindow()
{
    _window.create(sf::VideoMode(_resolution.x, _resolution.y), "Zappy");
}

/**
 * @brief Get the window object
 *
 * @return sf::RenderWindow&
 */
sf::RenderWindow &Renderer::getWindow()
{
    return _window;
}

/**
 * @brief Set the resolution of the window
 *
 * @param x
 * @param y
 */
void Renderer::setResolution(int x, int y)
{
    _resolution = sf::Vector2u(x, y);
}

/**
 * @brief Set the resolution of the window
 *
 * @param resolution
 */
void Renderer::setResolution(sf::Vector2u resolution)
{
    _resolution = resolution;
}

/**
 * @brief Get the resolution of the window
 *
 * @return sf::Vector2u
 */
sf::Vector2u Renderer::getResolution() const
{
    return _resolution;
}

/**
 * @brief Draw a drowable object on the window
 * 
 * @param shape
 */
void Renderer::draw(sf::Drawable &drawable)
{
    _window.draw(drawable);
}
