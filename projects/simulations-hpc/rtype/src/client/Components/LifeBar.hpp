/*
** EPITECH PROJECT, 2024
** Visual Studio Live Share (Espace de travail)
** File description:
** HealthBar.hpp
*/

#ifndef LIFEBAR_HPP_
#define LIFEBAR_HPP_

#include <unordered_map>
#include <SFML/Graphics.hpp>
#include "../../server/ECS/Components/Component.hpp"
#include "../Utils/HealthBar.hpp"

class LifeBar: public Component {
    public:
        LifeBar() = default;
        ~LifeBar() noexcept = default;

        void draw(sf::RenderWindow &window);
        void info() const override;
        void dropEntity(int id) override;

        void removeLifeBar(std::size_t id);
        void addLifeBar(std::size_t id, std::shared_ptr<HealthBar> lifeBar);
        void setLifeBar(std::size_t id, float life);
        void setPosition(std::size_t id, sf::Vector2f position);
        void setMaxLife(std::size_t id, float maxLife);
        void setMinLife(std::size_t id, float minLife);
    private:
        std::unordered_map<std::size_t, std::shared_ptr<HealthBar>> _lifeBars;
};

#endif /* !LIFEBAR_HPP_ */
