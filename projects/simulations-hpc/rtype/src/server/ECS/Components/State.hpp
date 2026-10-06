/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** State
*/

#ifndef STATE_HPP_
#define STATE_HPP_

#include "Component.hpp"
#include <SFML/Graphics.hpp>

typedef enum {
    UNDEFINED = -1,
    DEAD,
    ALIVE,
    INVINCIBLE
} StateType;

class State : public Component {
    public:
        State() = default;
        virtual ~State() = default;

        void info() const override;
        void dropEntity(int idx) override;

        void setState(std::size_t idx, const int);
        int getState(std::size_t idx) const;

    protected:
        std::unordered_map<std::size_t, int> _state;
};

#endif /* !STATE_HPP_ */
