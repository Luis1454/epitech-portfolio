#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include "UdpClient.hpp"
#include "../server/ECS/Components/Position.hpp"
#include "../server/ECS/Components/Velocity.hpp"
#include "../server/ECS/Components/Player.hpp"
#include "../server/ECS/Systems/Motion.hpp"
#include "game.hpp"
#include "story.hpp"
#include "setting.hpp"
#include <string>

enum class MenuState {
    MainMenu,
    GamePage,
    Exit
};

class Menu {
public:
    Menu() = default;
    Menu(sf::RenderWindow &window, ECS &ecs);
    ~Menu() = default;
    void run(UdpClient &client);
    void setPlayerName(const std::string& name);
    MenuState getCurrentState() const;

private:
    ECS &_ecs;
    Game _game;
    Story _story;
    Setting _setting;

    sf::RenderWindow &_window;

    MenuState currentState;

    void handleEvents(UdpClient &client);
    void update();
    void render();

    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    float backgroundOffset;

    sf::Font font;
    sf::Text titleText;
    sf::Text gameButton;
    sf::Text settingsButton;
    sf::Text StoryButton;

    std::string playerName;
};

#endif
