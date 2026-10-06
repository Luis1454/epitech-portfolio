/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** RigidBody
*/

#ifndef RIGIDBODY_HPP_
#define RIGIDBODY_HPP_

#include "Component.hpp"
#include <SFML/Graphics.hpp>

class RigidBody : public Component {
    public:
        RigidBody() = default;
        ~RigidBody() = default;

        void info() const;
        std::vector<std::pair<int, int>> intersect(std::vector<int> other) const;
        void dropEntity(int idx) override;

        void setBody(std::size_t idx, const sf::FloatRect &body);
        sf::FloatRect getBody(std::size_t idx) const;

    protected:
        std::unordered_map<std::size_t, sf::FloatRect> _body;
};

#endif /* !RIGIDBODY_HPP_ */
