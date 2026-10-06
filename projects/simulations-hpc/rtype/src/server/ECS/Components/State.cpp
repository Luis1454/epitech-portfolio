/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** State
*/

#include "State.hpp"

void State::info() const {
    std::cout << "States (" << _state.size() << "):" << std::endl;
    for (auto &it : _state)
        std::cout << "  " << it.first << ": " << it.second << std::endl;
}

void State::dropEntity(int idx) {
    Component::dropEntity(idx);

    _state.erase(idx);
}

int State::getState(std::size_t idx) const
{
    return _state.at(idx);
}

void State::setState(std::size_t idx, int state)
{
    _state.insert_or_assign(idx, state);
}
