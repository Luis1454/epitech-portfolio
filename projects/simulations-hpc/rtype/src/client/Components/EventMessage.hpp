/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** HealthBar.hpp
*/

#ifndef EVENTMESSAGE_HPP_
#define EVENTMESSAGE_HPP_

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../../server/ECS/Components/Component.hpp"

class EventMessage: public Component {
    public:
        EventMessage();
        ~EventMessage() noexcept = default;

        void draw(sf::RenderWindow &window);
        void info() const override;
        void dropEntity(int id) override;

        void setEventMessage(std::string name, std::shared_ptr<sf::Text> text);
        void setEventMessage(std::string name, std::string text);
        void removeEventMessage(std::string name);

        void setFont(std::string name, std::shared_ptr<sf::Font> font);
        void removeFont(std::string name);

        std::shared_ptr<sf::Text> getText(std::string name) const;
        std::shared_ptr<sf::Font> getFont(std::string name) const;

    private:
        std::unordered_map<std::string, std::shared_ptr<sf::Font>> _fonts;
        std::unordered_map<std::string, std::shared_ptr<sf::Text>> _texts;
};

#endif /* !EVENTMESSAGE_HPP_ */
