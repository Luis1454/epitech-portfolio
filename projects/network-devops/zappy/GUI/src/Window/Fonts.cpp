/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Fonts
*/

#include "../../include/Renderer.hpp"

/**
 * @brief Add a font to the renderer
 * 
 * @param name
 * @param path
 */
void Renderer::setFont(std::string name, std::string path)
{
    _fonts[name].loadFromFile(path);
}

/**
 * @brief Get a font from the renderer
 * 
 * @param name
 * @return sf::Font
 */
sf::Font &Renderer::getFont(std::string name)
{
    return _fonts[name];
}

/**
 * @brief Get all the fonts from the renderer
 * 
 * @return std::map<std::string, sf::Font>
 */
std::map<std::string, sf::Font> Renderer::getFonts() const
{
    return _fonts;
}