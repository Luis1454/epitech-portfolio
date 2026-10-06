/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** setting.hpp
*/

#ifndef SETTING_HPP_
#define SETTING_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <vector>
#include <string>
#include <stdexcept>
// #include "menu.hpp"
// #include "game.hpp"
#include <array>

class Setting {
public:
    Setting();
    ~Setting();

    void run(sf::RenderWindow &window);
    void render(sf::RenderWindow &window);
    bool handleEvents(sf::RenderWindow &window);
    void update();
    void saveSettings();

private:
    int selectedShip;
    int selectedMusic;
    std::vector<std::string> shipNames;
    std::vector<std::string> musicFiles;
    sf::Font font;
    sf::Text titleText;
    sf::Text shipText;
    sf::Text musicText;
    // sf::Music music;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    float backgroundOffset;
    std::array<sf::Texture, 2> shipTextures;
    std::vector<sf::Sprite> shipSprites;
    std::string shipName;
    sf::Text saveButton;
};
#endif /* !SETTING_HPP_ */
