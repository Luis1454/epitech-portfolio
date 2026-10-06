#ifndef SPRITE_HPP_
#define SPRITE_HPP_
#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include "../../server/ECS/Components/Component.hpp"
#include <map>

class Sprite : public Component {
public:
    // Constructeur prenant le chemin de la texture
    Sprite() = default;

    // Accès au sprite SFML
    sf::Sprite& getSprite(std::string name);

    void dropEntity(int id) override;
    void info() const override;

    void draw(sf::RenderWindow& window);
    void addPlayer(std::size_t id, std::string spriteName);
    void removePlayer(std::size_t id);
    void removeSprite(std::string name);

    void setSprite(std::string name, sf::Texture texture);
    void setSprite(std::string name, sf::Sprite sprite);
    void setSprite(std::string name, std::string path);

    void setTexture(std::string name, sf::Texture texture);
    void setTexture(std::string name, std::string path);
    sf::Texture& getTexture(std::string name);

private:
    std::unordered_map<std::size_t, std::string> _players;
    std::unordered_map<std::string, sf::Sprite> _sprites;
    std::unordered_map<std::string, sf::Texture> _textures;
};

#endif // SPRITE_HPP_
