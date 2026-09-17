/*
** EPITECH PROJECT, 2024
** AComponent.cpp
** File description:
** AComponent
*/

#include "AComponent.hpp"
#include <iostream>
#include <algorithm>

void nts::AComponent::setLink(std::size_t pin, const
std::unique_ptr<AComponent> &other, std::size_t otherPin) {
    _links[pin] = std::make_pair(other->getName(), otherPin);
}

void nts::AComponent::setChild(std::size_t pin, const
std::unique_ptr<AComponent> &other, std::size_t otherPin) {
    _childs[pin] = std::make_pair(other->getName(), otherPin);
}

void nts::AComponent::setPin(std::size_t pin, nts::Tristate state)
{
    for (auto it = _pins.begin(); it != _pins.end(); it++)
        if (it->first == pin) {
            it->second = state;
            return;
        }
    _pins.insert(std::pair<std::size_t, nts::Tristate>(pin, state));
}

void nts::AComponent::setOldPin(std::size_t pin, nts::Tristate state)
{
    for (auto it = _oldPins.begin(); it != _oldPins.end(); it++)
        if (it->first == pin) {
            it->second = state;
            return;
        }
    _oldPins.insert(std::pair<std::size_t, nts::Tristate>(pin, state));
}

void nts::AComponent::setPinState(std::string state)
{
    if (state == "0")
        _pins[_refPin] = nts::Tristate::False;
    else if (state == "1")
        _pins[_refPin] = nts::Tristate::True;
    else
        _pins[_refPin] = nts::Tristate::Undefined;
}

nts::Tristate nts::AComponent::getOldPin(std::size_t pin)
{
    for (auto it = _oldPins.begin(); it != _oldPins.end(); it++)
        if (it->first == pin)
            return it->second;
    return nts::Tristate::Undefined;
}

nts::Tristate nts::AComponent::getPin(std::size_t pin)
{
    for (auto it = _pins.begin(); it != _pins.end(); it++)
        if (it->first == pin)
            return it->second;
    return nts::Tristate::Undefined;
}

std::string nts::AComponent::getPinState()
{
    nts::Tristate state = getOldPin(_refPin);

    return state == nts::Tristate::True ? "1" :
    state == nts::Tristate::False ? "0" : "U";
}

std::map<std::size_t, nts::Tristate> nts::AComponent::getPins()
{
    return _pins;
}

nts::Tristate nts::AComponent::compute(std::size_t tick)
{
    (void)tick;
    return nts::Tristate::Undefined; 
}

void nts::AComponent::simulate(std::size_t tick, std::vector<std::unique_ptr<nts::AComponent>> &components)
{

}
