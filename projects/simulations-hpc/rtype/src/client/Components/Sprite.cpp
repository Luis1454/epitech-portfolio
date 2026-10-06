#include "Sprite.hpp"
#include <stdexcept>

void Sprite::addPlayer(std::size_t id, std::string spriteName) {
    _players[id] = spriteName;
}

void Sprite::removePlayer(std::size_t id) {
    _players.erase(id);
}

void Sprite::setSprite(std::string name, sf::Texture texture) {
    _textures[name] = texture;
    _sprites[name].setTexture(_textures[name]);
}

void Sprite::setSprite(std::string name, sf::Sprite sprite) {
    _sprites[name] = sprite;
}

void Sprite::setSprite(std::string name, std::string path) {
    sf::Texture texture;

    texture.loadFromFile(path);
    _textures[name] = texture;
    _sprites[name].setTexture(_textures[name]);
}

void Sprite::setTexture(std::string name, sf::Texture texture) {
    _textures[name] = texture;
}

void Sprite::setTexture(std::string name, std::string path) {
    sf::Texture texture;

    texture.loadFromFile(path);
    _textures[name] = texture;
}

sf::Texture& Sprite::getTexture(std::string name) {
    return _textures[name];
}

void Sprite::removeSprite(std::string name) {
    _sprites.erase(name);
}

// Retourne le sprite SFML
sf::Sprite& Sprite::getSprite(std::string name) {
    return _sprites[name];
}

void Sprite::info() const {
    std::cout << "Sprite (" << _sprites.size() << "):" << std::endl;
    for (const auto &sprite : _sprites)
        std::cout << "- " << sprite.first << " : " << sprite.second.getTexture() << std::endl;
}

void Sprite::dropEntity(int id) {
    Component::dropEntity(id);

    removeSprite("entity_"+std::to_string(id));
    removePlayer(id);
}

void Sprite::draw(sf::RenderWindow &window) {
    if (!window.isOpen())
        return;

    for (auto &id : getEntities())
        if (_sprites.find("entity_"+std::to_string(id.first)) != _sprites.end())
            window.draw(_sprites["entity_"+std::to_string(id.first)]);
}
