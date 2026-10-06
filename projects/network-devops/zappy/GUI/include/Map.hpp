/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Map
*/

#ifndef MAP_HPP_
#define MAP_HPP_

#include <SFML/Graphics.hpp>
#include <memory>

#include "Tile.hpp"
#include "Team.hpp"
#include "Player.hpp"
#include "Resources/Resource.hpp"
#include "Egg.hpp"

class Renderer;

class Map {
    public:
        Map();
        ~Map();

        void showTiles(Renderer &gui);
        void setTile(Tile &tile);
        Tile getTile(int x, int y);
        std::map<std::pair<int, int>, Tile> getTiles() const;

        void updateShape();
        void setShape(int x, int y);
        std::pair<int, int> getShape() const;

        void setTileSize(double x, double y);
        std::pair<double, double> getTileSize() const;

        void setSize(double x, double y);
        void setSize(sf::Vector2f size);
        std::pair<double, double> getSize() const;

        void setPos(double x, double y);
        std::pair<double, double> getPos() const;
        void updatePos(sf::Vector2f size);

        std::shared_ptr<Resource> getResource(std::string name);
        std::map<std::string, std::shared_ptr<Resource>> getResources() const;
        void setResource(std::string name, std::shared_ptr<Resource> resource);

        void dropPlayer(int id);
        Player &getPlayer(int id);
        void addPlayer(Player player);
        std::vector<Player> getPlayers();
        void showPlayers(Renderer &gui);

        void setPlayerId(int id);
        void setPlayerLevel(int id, int level);
        void setPlayerPosition(int id, sf::Vector2f pos);
        void setPlayerOrientation(int id, int orientation);
        void setPlayerInventory(int id, Inventory inventory);

        void setTeam(std::string name);
        void dropTeam(std::string name);
        std::vector<std::shared_ptr<Team>> getTeams() const;
        std::shared_ptr<Team> getTeam(std::string name);

        void setWinningTeam(std::string name);
        std::shared_ptr<Team> getWinningTeam() const;

        void setEgg(Egg egg);
        Egg getEgg(int id);
        void dropEgg(int id);
        void showEggs(Renderer &gui);

        void expulsePlayer(int id);
        void forkPlayer(int id);

    private:
        std::pair<double, double> _tileSize;
        std::pair<double, double> _size;
        std::pair<double, double> _pos;
        std::pair<int, int> _shape;
        std::map<int, Player> _players;
        std::map<std::pair<int, int>, Tile> _tiles;
        std::map<std::string, std::shared_ptr<Team>> _teams;
        std::map<std::string, std::shared_ptr<Resource>> _resources;
        std::map<int, Egg> _eggs;
        std::shared_ptr<Team> _winner;
};

#endif /* !MAP_HPP_ */
