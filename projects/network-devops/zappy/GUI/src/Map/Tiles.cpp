/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Tiles
*/

#include "../../include/Renderer.hpp"

/**
 * @brief Draw the tiles on the window
 */
void Map::showTiles(Renderer &gui)
{
    sf::Sprite rectangle;
    sf::Text text("", gui.getFont("Arial"), 16);

    rectangle.setTexture(gui.getTexture("tile"));
    rectangle.setScale(sf::Vector2f(
        ((double)_tileSize.first) / rectangle.getLocalBounds().width,
        ((double)_tileSize.second) / rectangle.getLocalBounds().height
    ));
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(1);
    for (auto &tile : _tiles) {
        rectangle.setPosition(sf::Vector2f(
            _pos.first + tile.second.getPos().x * _tileSize.first,
            _pos.second + tile.second.getPos().y * _tileSize.second
        ));
        gui.draw(rectangle);

        std::vector<Item> items = {
            tile.second.getItem("food"),
            tile.second.getItem("linemate"),
            tile.second.getItem("deraumere"),
            tile.second.getItem("sibur"),
            tile.second.getItem("mendiane"),
            tile.second.getItem("phiras"),
            tile.second.getItem("thystame")
        };

        for (int x = 0; x < (int)items.size(); x++) {
            if (!items[x].getQuantity())
                continue;
            sf::Sprite sprite = items[x].getResource()->getSprite();
            sprite.setScale(sf::Vector2f(
                ((double)_tileSize.first) / items[x].getResource()->getSprite().getLocalBounds().width / 5.0,
                ((double)_tileSize.second) / items[x].getResource()->getSprite().getLocalBounds().height / 5.0
            ));
            sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
            sprite.setPosition(sf::Vector2f(
                rectangle.getPosition().x + items[x].getResource()->getOffset().x * rectangle.getGlobalBounds().width,
                rectangle.getPosition().y + items[x].getResource()->getOffset().y * rectangle.getGlobalBounds().height
            ));
            gui.draw(sprite);

            text.setString(std::to_string(items[x].getQuantity()));
            text.setOrigin(text.getLocalBounds().width, text.getLocalBounds().height);

            text.setPosition(sf::Vector2f(
                rectangle.getPosition().x + items[x].getResource()->getOffset().x * rectangle.getGlobalBounds().width + sprite.getGlobalBounds().width / 2,
                rectangle.getPosition().y + items[x].getResource()->getOffset().y * rectangle.getGlobalBounds().height + sprite.getGlobalBounds().height / 2
            ));
            gui.draw(text);
        }
    }
}

/**
 * @brief Set a tile in the tiles dictionary
 * 
 * @param tile tile to set
 */
void Map::setTile(Tile &tile)
{
    _tiles[std::pair<int, int>(tile.getPos().x, tile.getPos().y)] = tile;
}

/**
 * @brief Get a tile from the tiles dictionary
 * 
 * @param x x position of the tile
 * @param y y position of the tile
 * @return Tile 
 */
Tile Map::getTile(int x, int y)
{
    return _tiles[std::pair<int, int>(x, y)];
}

/**
 * @brief Get the tiles dictionary
 * 
 * @return std::map<std::pair<int, int>, Tile> 
 */
std::map<std::pair<int, int>, Tile> Map::getTiles() const
{
    return _tiles;
}

/**
 * @brief Set the default size of the tiles
 * 
 * @param x x size of the tile
 * @param y y size of the tile
 */

void Map::setTileSize(double x, double y)
{
    _tileSize = std::pair<double, double>(x, y);
}

/**
 * @brief Get the size of the tiles
 * 
 * @return std::pair<double, double> 
 */
std::pair<double, double> Map::getTileSize() const
{
    return _tileSize;
}
