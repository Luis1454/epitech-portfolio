/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** setting.cpp
*/


#include "setting.hpp"
#include <iostream>
#include <fstream>

Setting::Setting() : selectedShip(0) {
    shipNames = {"Red Falco", "White Eagle"};

    if (!font.loadFromFile("src/client/assets/nasa.otf")) {
        throw std::runtime_error("Erreur : Impossible de charger la police !");
    }
    std::vector<std::string> shipTextureFiles = {
        "src/client/assets/player.png",
        "src/client/assets/white.png"
        };

    for (size_t i = 0; i < shipTextureFiles.size(); ++i) {
        if (!shipTextures[i].loadFromFile(shipTextureFiles[i])) {
            throw std::runtime_error("Erreur : Impossible de charger la texture " + shipTextureFiles[i]);
        }
        sf::Sprite sprite;
        sprite.setTexture(shipTextures[i]);
        sprite.setScale(0.5f, 0.5f);
        sprite.setPosition(250, 200);
        shipSprites.push_back(sprite);
    }

    if (!backgroundTexture.loadFromFile("src/client/assets/bcg.png")) {
        throw std::runtime_error("Failed to load background image");
    }
    backgroundSprite.setTexture(backgroundTexture);

    titleText.setFont(font);
    titleText.setString("Settings");
    titleText.setCharacterSize(50);
    titleText.setPosition(200, 50);

    shipText.setFont(font);
    shipText.setCharacterSize(30);
    shipText.setPosition(200, 150);

    saveButton.setFont(font);
    saveButton.setString("Press enter to save");
    saveButton.setCharacterSize(30);
    saveButton.setPosition(200, 500);
}

Setting::~Setting() {
    // music.stop();
}

void Setting::saveSettings()
{
    std::ofstream file("src/client/assets/settings.json");
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier de sauvegarde.");
    }

    file << "{\n";
    file << "\t\"ship\": \"" << shipNames[selectedShip] << "\"\n";
    file << "}\n";

    file.close();
}

void Setting::run(sf::RenderWindow &window) {
    while (window.isOpen()) {
        if (handleEvents(window))
            break;
        update();
        render(window);
    }
}

void Setting::render(sf::RenderWindow &window) {
    window.clear();

    shipText.setString("Ship  : " + shipNames[selectedShip]);
    backgroundSprite.setPosition(backgroundOffset, 0);
    window.draw(backgroundSprite);

    backgroundSprite.setPosition(backgroundOffset + static_cast<float>(backgroundTexture.getSize().x), 0);
    window.draw(backgroundSprite);

    window.draw(titleText);
    window.draw(shipText);
    window.draw(musicText);
    window.draw(saveButton);
    window.draw(shipSprites[selectedShip]);
    window.display();
}

bool Setting::handleEvents(sf::RenderWindow &window) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                selectedShip = (selectedShip - 1 + shipNames.size()) % shipNames.size();
            else if (event.key.code == sf::Keyboard::Down)
                selectedShip = (selectedShip + 1) % shipNames.size();
            else if (event.key.code == sf::Keyboard::Enter) {
                saveSettings();
                return true;
            }
        }
    }
    return false;
}

// void Setting::setShipName(std::string name) {
//     shipName = name;
// }

// std::string Setting::getShipName() {
//     return shipName;
// }

void Setting::update() {
    backgroundOffset -= 0.1f;
    if (backgroundOffset <= -static_cast<float>(backgroundTexture.getSize().x)) {
        backgroundOffset = 0.0f;
    }
}