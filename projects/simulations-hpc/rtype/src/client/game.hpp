#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "../server/ECS/ECS.hpp"
#include "Components/Sprite.hpp"
#include "UdpClient.hpp"

class Game {
public:
    Game(sf::RenderWindow &window, ECS &ecs);
    ~Game() = default;
    void update();
    void render(sf::RenderWindow& window);
    bool handleEvents(sf::RenderWindow& window, UdpClient& client);
    void run(sf::RenderWindow& window, UdpClient &client);
    void init(ECS &ecs);

private:
    ECS &ecs;
    sf::Font font;
    sf::Text gameText;
    sf::Texture backgroundTexture;
    sf::Sprite backgroundSprite;
    float backgroundOffset;
    int playerId;
    bool _nokeyPressed =  true;

    sf::Text backButton;
};

#endif /* GAME_HPP */
