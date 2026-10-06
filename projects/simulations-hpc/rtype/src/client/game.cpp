#include "game.hpp"
#include <stdexcept>
#include <iostream>
#include "../Protocol/Protocol.hpp"
#include "Utils/HealthBar.hpp"

Game::Game(sf::RenderWindow &window, ECS &ecs) : backgroundOffset(0.0f), ecs(ecs)
{
    if (!font.loadFromFile("src/client/assets/nasa.otf"))
        throw std::runtime_error("Failed to load font");

    if (!backgroundTexture.loadFromFile("src/client/assets/bcg.png"))
        throw std::runtime_error("Failed to load background image");
    backgroundSprite.setTexture(backgroundTexture);

    gameText.setFont(font);
    gameText.setString("Game Page");
    gameText.setCharacterSize(30);
    gameText.setFillColor(sf::Color::White);
    gameText.setPosition(100, 50);

    backButton.setFont(font);
    backButton.setString("Back");
    backButton.setCharacterSize(30);
    backButton.setFillColor(sf::Color::White);
    backButton.setPosition(50, 500);
}

void Game::run(sf::RenderWindow& window, UdpClient& client)
{
    while (window.isOpen()) {
        if (handleEvents(window, client))
            break;
        update();
        render(window);
    }
}

bool Game::handleEvents(sf::RenderWindow& window, UdpClient& client) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
            exit(0);
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            sf::Vector2i mousePos = sf::Mouse::getPosition(window);
            sf::Vector2f worldPos(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y));
            if (backButton.getGlobalBounds().contains(worldPos))
                return true;
        }

        std::map<sf::Keyboard::Key, std::size_t> keyMap = {
            {sf::Keyboard::Up, 1},
            {sf::Keyboard::Down, 2},
            {sf::Keyboard::Left, 3},
            {sf::Keyboard::Right, 4}
        };

        if (keyMap.find(event.key.code) != keyMap.end()) {
            _nokeyPressed = false;
            std::vector<field_t> fields = {};
            fields.push_back({RequestType::r_ReceivePlayerMove, 8});
            fields.push_back({(uint16_t)ecs.getClientId(), 16});
            fields.push_back({(uint16_t)keyMap[event.key.code], 8});
            client.addRequest(fields);
        }
        if (event.type == sf::Event::KeyReleased) {
            _nokeyPressed = true;
            std::vector<field_t> fields = {};
            fields.push_back({RequestType::r_ReceivePlayerMove, 8});
            fields.push_back({(uint16_t)ecs.getClientId(), 16});
            fields.push_back({0, 8});
            client.addRequest(fields);
        }
        if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
            std::vector<field_t> fields = {};
            fields.push_back({9, 8});
            fields.push_back({(uint16_t)ecs.getClientId(), 16});
            fields.push_back({0, 8});
            Protocol<Byte> protocol;
            protocol.resizeBuffer(64);
            protocol.setBuffer(protocol.createPacket(fields));
            protocol.runRequest(ecs);
            fields = {};
            for (auto &byte : protocol.getBuffer())
                fields.push_back({byte, 8});
            client.addRequest(fields);
        }
    }
    return false;
}

void Game::init(ECS &ecs) {}

void Game::update() {
    backgroundOffset -= 0.1f;
    if (backgroundOffset <= -static_cast<float>(backgroundTexture.getSize().x))
        backgroundOffset = 0.0f;
}

void Game::render(sf::RenderWindow& window) {
    window.clear(sf::Color::Black);
    backgroundSprite.setPosition(backgroundOffset, 0);
    window.draw(backgroundSprite);
    backgroundSprite.setPosition(backgroundOffset + static_cast<float>(backgroundTexture.getSize().x), 0);
    window.draw(backgroundSprite);
    window.draw(gameText);
    window.draw(backButton);

    ecs.update();
    window.display();
}
