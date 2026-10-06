/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Projectiles
*/

#ifndef PROJECTILES_HPP
#define PROJECTILES_HPP

#include "Player.hpp"

class Projectiles : public Component {
    public:
        Projectiles() = default;
        ~Projectiles() = default;

        void info() const override;
        void dropEntity(int idx) override;

        void setName(std::size_t idx, const std::string &name);
        std::string getName(std::size_t idx) const;

        void setDamage(std::size_t idx, float damage);
        float getDamage(std::size_t idx);

        void setEmitter(std::size_t idx, std::size_t emitter);
        std::size_t getEmitter(std::size_t idx);

    protected:
        std::unordered_map<std::size_t, std::string> _names;
        std::unordered_map<std::size_t, int> _damages;
        std::unordered_map<std::size_t, std::size_t> _emitters;
};

#endif // PROJECTILES_HPP
