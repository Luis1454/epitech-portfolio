/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Players
*/

#include "../../include/Renderer.hpp"

/**
 * @brief Add a player to the renderer
 * 
 * @param player
 */
void Map::addPlayer(Player player)
{
    _players[player.getId()] = player;
}

/**
 * @brief Get all the players
 * 
 * @return std::vector<Player>
 */
std::vector<Player> Map::getPlayers()
{
    std::vector<Player> players;

    for (auto &player : _players)
        players.push_back(player.second);
    return players;
}

/**
 * @brief Get a player by id
 * 
 * @param id
 * @return Player
 */
Player &Map::getPlayer(int id)
{
    if (_players.find(id) != _players.end())
        return _players[id];
    return _players.at(0);
}

/**
 * @brief Drop a player
 * 
 * @param id
 */
void Map::dropPlayer(int id)
{
    if (_players.find(id) != _players.end())
        _players.erase(id);
}

/**
 * @brief Display all the players
 */
void Map::showPlayers(Renderer &gui)
{
    sf::Sprite sprite;
    sf::Text text("", gui.getFont("Arial"), 16);

    sprite.setTexture(gui.getTexture("players"));
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(1);
    for (auto &player : _players) {
        std::map<int, std::string> poses = {
            {1, "down"},
            {2, "right"},
            {3, "up"},
            {4, "left"}
        };
        if (player.second.getTeam() == nullptr)
            continue;
        sprite.setTextureRect(player.second.getTeam()->getPose(poses[player.second.getOrientation()]));
        sprite.setPosition(sf::Vector2f(
            _pos.first + player.second.getPosition().x * _tileSize.first,
            _pos.second + player.second.getPosition().y * _tileSize.second
        ));
        gui.draw(sprite);

        text.setOrigin(text.getGlobalBounds().width, text.getGlobalBounds().height);
        text.setString(std::to_string(player.second.getLevel()));
        text.setPosition(sf::Vector2f(
            sprite.getPosition().x + _tileSize.first / 2,
            sprite.getPosition().y + _tileSize.second / 2
        ));
        gui.draw(text);
        player.second.getInventory().display(gui.getWindow(), sf::Vector2f(
            sprite.getPosition().x + _tileSize.first / 2,
            sprite.getPosition().y + _tileSize.second / 2
        ), gui.getFont("Arial"));
    }
}

/**
 * @brief Set the player id
 * 
 * @param id
 */
void Map::setPlayerId(int id)
{
    _players[id].setId(id);
}

/**
 * @brief Set the player position
 * 
 * @param id
 * @param pos
 */
void Map::setPlayerPosition(int id, sf::Vector2f pos)
{
    if (_players.find(id) != _players.end())
        _players[id].setPosition(pos);
}

/**
 * @brief Set the player orientation
 * 
 * @param id
 * @param orientation
 */
void Map::setPlayerOrientation(int id, int orientation)
{
    if (_players.find(id) != _players.end())
        _players[id].setOrientation(orientation);
}

/**
 * @brief Set the player level
 * 
 * @param id
 * @param level
 */
void Map::setPlayerLevel(int id, int level)
{
    if (_players.find(id) != _players.end())
        _players[id].setLevel(level);
}

/**
 * @brief Set the player inventory
 * 
 * @param id
 * @param inventory
 */
void Map::setPlayerInventory(int id, Inventory inventory)
{
    if (_players.find(id) != _players.end())
        _players[id].setInventory(inventory);
}

/**
 * @brief Set winning team
 * 
 * @param name
 */
void Map::setWinningTeam(std::string name)
{
    _winner = getTeam(name);
}

/**
 * @brief Get the winning team
 * 
 * @return std::string
 */
std::shared_ptr<Team> Map::getWinningTeam() const
{
    return _winner;
}

/**
 * @brief Expulse a player
 * 
 * @param id
 */
void Map::expulsePlayer(int id)
{
    if (_players.find(id) != _players.end())
        _players.erase(id);
}

/**
 * @brief Fork a player
 * 
 * @param id
 */
void Map::forkPlayer(int id)
{
    if (_players.find(id) != _players.end())
        _players.erase(id);
}