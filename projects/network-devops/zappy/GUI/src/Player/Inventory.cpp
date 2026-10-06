/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** inventory.cpp
*/

#include "../../include/Inventory.hpp"

Inventory::Inventory()
{
}

Inventory::~Inventory()
{
}

void Inventory::setItem(std::shared_ptr<Resource> resource, int qty)
{
    std::string name = resource->getName();

    if (_items.find(name) != _items.end())
        _items[name].setQuantity(_items[name].getQuantity() + qty);
    else
        _items[name] = Item(resource, qty);
}

void Inventory::dropItem(std::string item, int qty)
{
    if (_items.find(item) != _items.end()) {
        _items[item].setQuantity(_items[item].getQuantity() - qty);
        if (_items[item].getQuantity() <= 0)
            _items.erase(item);
    }
}

void Inventory::dropItem(std::string item)
{
    if (_items.find(item) != _items.end())
        _items.erase(item);
}

Item Inventory::getItem(std::string item)
{
    return _items[item];
}

void Inventory::display(sf::RenderWindow &window, sf::Vector2f pos, sf::Font &font)
{
    sf::RectangleShape rect;
    sf::Sprite sprite;
    sf::Text text("", font, 16);
    text.setFillColor(sf::Color::White);
    text.setOutlineThickness(1);

    rect.setSize({150, 35});
    rect.setFillColor(sf::Color(0, 0, 0, 150));
    rect.setPosition(pos);
    pos.x += 5;
    pos.y += 5;
    window.draw(rect);

    for (auto &item : _items) {
        sprite = item.second.getResource()->getSprite();
        sprite.setPosition(pos);
        window.draw(sprite);
        pos.x += 20;
    }

    pos.x = rect.getPosition().x + 5;
    for (auto &item : _items) {
        text.setString(std::to_string(item.second.getQuantity()));
        text.setOrigin(-sprite.getGlobalBounds().width / 2, -sprite.getGlobalBounds().height / 2);
        text.setPosition(pos);
        window.draw(text);
        pos.x += 20;
    }
}
