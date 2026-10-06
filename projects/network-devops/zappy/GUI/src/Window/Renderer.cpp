/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Renderer.cpp
*/

#include "../../include/Renderer.hpp"
#include "../../include/Map.hpp"

/**
 * @brief Construct a new Renderer:: Renderer object
 * 
*/
Renderer::Renderer()
{
    _resolution = {1920, 1080};

    initWindow();
    setView(sf::View(sf::FloatRect(0, 0, _resolution.x, _resolution.y)));

    setFont("Arial", "GUI/assets/fonts/arial.ttf");

    setTexture("gems", "GUI/assets/textures/gems.png");
    setTexture("tile", "GUI/assets/textures/tile.jpg");
    setTexture("players", "GUI/assets/textures/players.png");
    setTexture("egg", "GUI/assets/textures/egg.png");

    _maps["default"] = Map();
    _maps["default"].setPos(0, 0);
    _maps["default"].setSize(_resolution.x, _resolution.y);

    for (auto &resource : _maps["default"].getResources())
        _maps["default"].getResource(resource.first)->setSprite(_textures["gems"]);

    _eggsSprites["default"] = sf::Sprite(_textures["egg"]);
}

/**
 * @brief Destroy the Renderer:: Renderer object
 * 
*/
Renderer::~Renderer()
{
}

/**
 * @brief Render the GUI
 */
void Renderer::render()
{
    _aspectRatio = (double)_resolution.x / _resolution.y;
    _view.setSize(_resolution.x, _resolution.y);
    _view.setCenter(_resolution.x / 2.0, _resolution.y / 2.0);
    _window.setView(_view);
    _window.clear();
    drawMap("default");
    _window.display();
}

/**
 * @brief Draw a specific map
 * 
 * @param std::string map
 */
void Renderer::drawMap(std::string map)
{
    _maps[map].showTiles(*this);
    _maps[map].showPlayers(*this);
    _maps[map].showEggs(*this);
    draw(_scoreboard);
}

/**
 * @brief Get a map
 * 
 * @param std::string map
 * @return Map
 */
Map &Renderer::getMap(std::string map)
{
    return _maps[map];
}

/**
 * @brief Get all the maps
 * 
 * @return std::map<std::string, Map>
 */
std::map<std::string, Map> Renderer::getMaps() const
{
    return _maps;
}

/**
 * @brief Set a map
 * 
 * @param std::string name
 * @param Map map
 */
void Renderer::setMap(std::string name, Map map)
{
    _maps[name] = map;
}

void Renderer::updateScoreboard()
{
    _scoreboard.getInfos().clear();
    sf::Vector2f size = {300, 50*10};
    sf::Vector2f pos = {_resolution.x - size.x, 20};
    sf::Text text("", getFont("Arial"), 16);
    _scoreboard.getBackground().setPosition({pos.x - 20, pos.y - 10});
    _scoreboard.getBackground().setSize({size.x + 10, size.y});
    _scoreboard.getBackground().setFillColor(sf::Color(0, 0, 0, 147));
    _scoreboard.setInfo("Players", Info("Players", pos, text));
    _scoreboard.setInfo("Level", Info("Level", {pos.x + 100, pos.y}, text));
    _scoreboard.setInfo("Team", Info("Team", {pos.x + 200, pos.y}, text));

    int i = 1;
    int offset = 15;
    for (auto &player : _maps["default"].getPlayers()) {
        _scoreboard.setInfo(std::to_string(player.getId()), Info(std::to_string(player.getId()), {pos.x, pos.y + i * offset}, text));
        _scoreboard.setInfo(std::to_string(player.getId())+"_lvl", Info(std::to_string(player.getLevel()), {pos.x + 100, pos.y + i * offset}, text));
        _scoreboard.setInfo(std::to_string(player.getId())+"_team", Info(player.getTeam()->getName(), {pos.x + 200, pos.y + i * offset}, text));
        i++;
    }
}

void Renderer::setView(sf::View _view)
{
    _view = _view;
}

sf::View Renderer::getView() const
{
    return _view;
}
