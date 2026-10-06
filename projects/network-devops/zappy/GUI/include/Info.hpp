/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Info
*/

#ifndef INFO_HPP_
#define INFO_HPP_

#include <SFML/Graphics.hpp>

class Info : public sf::Drawable {
    public:
        Info();
        Info(std::string info, sf::Vector2f pos);
        Info(std::string info, sf::Vector2f pos, sf::Text text);
        ~Info();

        void setInfo(std::string info);
        std::string getInfo() const;

        void setPos(sf::Vector2f pos);
        sf::Vector2f getPos() const;

        void setStyle(sf::Text text);
        sf::Text getStyle() const;

        void draw(sf::RenderTarget &target, sf::RenderStates states) const override;

    private:
        sf::Text _text;
};

#endif /* !INFO_HPP_ */
