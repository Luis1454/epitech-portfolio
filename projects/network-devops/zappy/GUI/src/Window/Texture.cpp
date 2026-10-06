/*
** EPITECH PROJECT, 2024
** Texture.cpp
** File description:
** Texture
*/

#include "../../include/Renderer.hpp"

/**
 * @brief get the texture
 * 
 * @param name
 */
sf::Texture &Renderer::getTexture(std::string name)
{
    return _textures[name];
}

/**
 * @brief set the texture using a path
 * 
 * @param name
 * @param path
 */
void Renderer::setTexture(std::string name, std::string path)
{
    sf::Texture texture;

    texture.loadFromFile(path);
    _textures[name] = texture;
}

/**
 * @brief set the texture using a texture
 * 
 * @param name
 * @param texture
 */
void Renderer::setTexture(std::string name, sf::Texture texture)
{
    _textures[name] = texture;
}

/**
 * @brief get all the textures
 * 
 * @return std::map<std::string, sf::Texture>
 */
std::map<std::string, sf::Texture> Renderer::getTextures() const
{
    return _textures;
}
