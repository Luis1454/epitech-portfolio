/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** HealthBar.hpp
*/

#ifndef HEALTH_bar_HPP_
#define HEALTH_bar_HPP_

#include <SFML/Graphics.hpp>

class HealthBar {
    public:
        HealthBar(int min, int max, int value, sf::Vector2f position);
        ~HealthBar() = default;

        void draw(sf::RenderWindow &window) const;

        int getHealth() const;
        int getMaxHealth() const;
        void setHealth(int health);
        void setMaxHealth(int value);
        void setMinHealth(int value);
        void setPosition(sf::Vector2f position);


    private:
        sf::RectangleShape _border;
        sf::RectangleShape _healthBar;
        int _min;
        int _max;
        int _value;
};

#endif /* !HEALTH_bar_HPP_ */
