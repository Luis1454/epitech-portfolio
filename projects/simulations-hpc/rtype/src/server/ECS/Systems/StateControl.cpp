/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** StateControl
*/

#include "StateControl.hpp"
#include "../Components/Position.hpp"
#include "../Components/State.hpp"
#include "../Components/Health.hpp"
#include "../Components/Enemy.hpp"

StateControl::StateControl() {
    this->_name = "StateControl";
}

void StateControl::update()
{
    std::shared_ptr<Position> pos = getElement<Position>(0);
    std::shared_ptr<State> state = getElement<State>(0);
    std::shared_ptr<Health> health = getElement<Health>(0);
    std::shared_ptr<Enemy> enemy = getElement<Enemy>(0);

    if (pos == nullptr || state == nullptr || health == nullptr || enemy == nullptr)
        return;

    for (auto &e : pos->getEntities()) {
        if (state->getEntity(e.first) != nullptr
        && state->getState(e.first) != StateType::DEAD
        && state->getState(e.first) != StateType::INVINCIBLE
        && state->getState(e.first) != StateType::UNDEFINED
        && (pos->getX(e.first) < 0 || health->getHealth(e.first) <= 0)) {
            state->setState(e.first, StateType::DEAD);
            if (enemy->getEntity(e.first) != nullptr)
                enemy->addKill();
        }
    }
}
