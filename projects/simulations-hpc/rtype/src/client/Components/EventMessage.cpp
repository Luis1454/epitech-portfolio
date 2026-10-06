/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** HealthBar.cpp
*/

#include "EventMessage.hpp"

EventMessage::EventMessage() {
    _fonts["default"] = std::make_shared<sf::Font>();
    if (_fonts.find("default") == _fonts.end()) {
        std::cerr << "Error: Error while creating the font's pointer" << std::endl;
        return;
    }
    _fonts["default"]->loadFromFile("src/client/assets/nasa.otf");

    _texts["default"] = std::make_shared<sf::Text>();
    if (_texts.find("default") == _texts.end()) {
        std::cerr << "Error: Error while creating the text's pointer" << std::endl;
        return;
    }
    _texts["default"]->setFont(*_fonts["default"]);
    _texts["default"]->setCharacterSize(64);
    _texts["default"]->setFillColor(sf::Color::White);
    _texts["default"]->setPosition(1920 / 2, 1080 * (3.0f/7));
    _texts["default"]->setString("Default");
    _texts["default"]->setOrigin(
       _texts["default"]->getGlobalBounds().width / 2,
        _texts["default"]->getGlobalBounds().height / 2
    );
}

void EventMessage::info() const {
    std::cout << "EventMessage (" << _texts.size() << ")" << std::endl;
    for (auto &text : _texts)
        std::cout << " - " << text.first << " : " << text.second->getString().toUtf32().c_str() << std::endl;
}

void EventMessage::draw(sf::RenderWindow &window) {
    for (const auto &[name, text] : _texts)
        if (text != nullptr)
            window.draw(*text);
}

void EventMessage::dropEntity(int id) {
    Component::dropEntity(id);
}

void EventMessage::setEventMessage(std::string name, std::shared_ptr<sf::Text> text) {
    _texts.insert_or_assign(name, text);
}

void EventMessage::setEventMessage(std::string name, std::string text) {
    _texts.insert_or_assign(name, std::make_shared<sf::Text>(text, *_fonts["default"], 54));
    _texts[name]->setFillColor(sf::Color::White);
    _texts[name]->setPosition(1920 / 2, 1080 * (3.0f/7));
    _texts[name]->setOrigin(
        _texts[name]->getLocalBounds().width / 2,
        _texts[name]->getLocalBounds().height / 2
    );
}

void EventMessage::removeEventMessage(std::string name) {
    _texts.erase(name);
}

void EventMessage::setFont(std::string name, std::shared_ptr<sf::Font> font) {
    _fonts.insert_or_assign(name, font);
}

void EventMessage::removeFont(std::string name) {
    _fonts.erase(name);
}

std::shared_ptr<sf::Text> EventMessage::getText(std::string name) const {
    if (_texts.find(name) == _texts.end())
        return nullptr;
    return _texts.at(name);
}

std::shared_ptr<sf::Font> EventMessage::getFont(std::string name) const {
    if (_fonts.find(name) == _fonts.end())
        return nullptr;
    return _fonts.at(name);
}
