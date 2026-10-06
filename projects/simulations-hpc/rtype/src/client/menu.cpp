#include "menu.hpp"
#include <iostream>

Menu::Menu(sf::RenderWindow &window, ECS &ecs)
: backgroundOffset(0.0f), currentState(MenuState::MainMenu), _window(window), _ecs(ecs), _game(_window, _ecs) {

    if (!font.loadFromFile("src/client/assets/nasa.otf"))
        throw std::runtime_error("Failed to load font");

    if (!backgroundTexture.loadFromFile("src/client/assets/bcg.png"))
        throw std::runtime_error("Failed to load background image");

    backgroundSprite.setTexture(backgroundTexture);

    titleText.setFont(font);
    titleText.setString("R-Type Menu");
    titleText.setCharacterSize(50);
    titleText.setFillColor(sf::Color::White);
    titleText.setPosition(250, 50);

    gameButton.setFont(font);
    gameButton.setString("Game");
    gameButton.setCharacterSize(30);
    gameButton.setFillColor(sf::Color::White);
    gameButton.setPosition(50, 300);

    settingsButton.setFont(font);
    settingsButton.setString("Settings");
    settingsButton.setCharacterSize(30);
    settingsButton.setFillColor(sf::Color::White);
    settingsButton.setPosition(50, 350);

    StoryButton.setFont(font);
    StoryButton.setString("Story");
    StoryButton.setCharacterSize(30);
    StoryButton.setFillColor(sf::Color::White);
    StoryButton.setPosition(50, 400);
}

void Menu::run(UdpClient &client) {
    while (_window.isOpen()) {
        handleEvents(client);
        update();
        render();
    }
}

void Menu::handleEvents(UdpClient &client) {
    sf::Event event;

    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            _window.close();

        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Space) {
                Protocol<uint8_t> protocol;
                std::vector<field_t> fields;
                std::cout << "Escape key pressed" << std::endl;

                protocol.resizeBuffer(8);
                fields.push_back({9, 8});
                fields.push_back({(uint16_t)_ecs.getClientId(), 16});
                protocol.setBuffer(protocol.createPacket(fields));
                protocol.runRequest(_ecs);
                fields = {};
                for (auto &b : protocol.getBuffer())
                    fields.push_back({b, 8});
                client.addRequest(fields);
            }

            if (event.key.code == sf::Keyboard::Escape)
                _window.close();
        }
        if (event.type == sf::Event::MouseButtonPressed) {
            auto mousePos = sf::Mouse::getPosition(_window);

            if (gameButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                _game.run(_window, client);
            if (settingsButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                _setting.run(_window);
            if (StoryButton.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos)))
                _story.run(_window);
        }
    }
}

void Menu::update() {
    backgroundOffset -= 0.1f;

    if (backgroundOffset <= -static_cast<float>(backgroundTexture.getSize().x))
        backgroundOffset = 0.0f;
}

void Menu::render() {
    _window.clear();
    backgroundSprite.setPosition(backgroundOffset, 0);
    _window.draw(backgroundSprite);

    backgroundSprite.setPosition(backgroundOffset + static_cast<float>(backgroundTexture.getSize().x), 0);
    _window.draw(backgroundSprite);

    _window.draw(titleText);
    _window.draw(gameButton);
    _window.draw(settingsButton);
    _window.draw(StoryButton);

    _window.display();
}

MenuState Menu::getCurrentState() const {
    return currentState;
}

void Menu::setPlayerName(const std::string& name) {
    playerName = name;
}
                                                                                                                                                            