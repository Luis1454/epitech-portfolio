/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** health
*/

#ifndef HEALTH_HPP_
#define HEALTH_HPP_

#include "Component.hpp"
#include <SFML/Graphics.hpp>

class Health : public Component {
    public:
        Health() = default;
        ~Health() override = default;

        void info() const override;
        void dropEntity(int idx) override;
        int getHealth(std::size_t id) const;
        int getMaxHealth(std::size_t id) const;
        int getMinHealth(std::size_t id) const;

        void setHealth(std::size_t id, int health);
        void setMaxHealth(std::size_t id, int maxHealth);
        void setMinHealth(std::size_t id, int minHealth);
        void takeDamages(std::size_t id, int damages);
        void removeHealth(std::size_t id);
        // int getMaxHealth(std::size_t id) const;

    private:
        std::unordered_map<std::size_t, int> _healths;
        std::unordered_map<std::size_t, int> _maxHealths;
        std::unordered_map<std::size_t, int> _minHealths;
};

#endif /* !HEALTH_HPP_ */
