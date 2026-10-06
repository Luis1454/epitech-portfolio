/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** RENDERER.hpp
*/

#ifndef RENDERER_HPP_
#define RENDERER_HPP_

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

#include "Scoreboard.hpp"
#include "Player.hpp"
#include "Map.hpp"
#include "Inventory.hpp"

class Renderer {
    public:
        Renderer();
        ~Renderer();

        int getPort() const;
        void setPort(int port);

        void setResolution(int x, int y);
        void setResolution(sf::Vector2u resolution);
        sf::Vector2u getResolution() const;

        sf::Font &getFont(std::string name);
        std::map<std::string, sf::Font> getFonts() const;
        void setFont(std::string name, std::string path);

        void initWindow();
        sf::RenderWindow &getWindow();

        void eventHandler();
        sf::Event &getEvent();

        std::string getState() const;
        void setState(std::string state);

        Map &getMap(std::string name);
        std::map<std::string, Map> getMaps() const;
        void setMap(std::string name, Map map);

        sf::Texture &getTexture(std::string name);
        std::map<std::string, sf::Texture> getTextures() const;
        void setTexture(std::string name, std::string path);
        void setTexture(std::string name, sf::Texture texture);

        Scoreboard &getScoreboard();
        void setScoreboard(Scoreboard scoreboard);
        void updateScoreboard();

        void draw(sf::Drawable &drawable);
        void drawMap(std::string map);
        void render();

        void setFrequency(int frequency);
        int getFrequency() const;

        int getIncantation() const;

        void setEggSprite(std::string name, sf::Sprite &sprite);
        sf::Sprite &getEggSprite(std::string name);

        void setView(sf::View _view);
        sf::View getView() const;

        

    private:
        int _port;
        sf::Event _event;
        sf::RenderWindow _window;
        sf::Vector2u _resolution;
        Scoreboard _scoreboard;
        sf::View _view;

        std::map<std::string, Map> _maps;
        std::map<std::string, sf::Font> _fonts;
        std::map<std::string, sf::Texture> _textures;
        std::map<std::string, sf::Sprite> _eggsSprites;

        std::string _state;
        std::string _msg;
        int _frequency;
        int _pin;
        int _x;
        int _y;
        int _incantation;
        double _aspectRatio;
};

#endif /* !RENDERER_HPP_ */
