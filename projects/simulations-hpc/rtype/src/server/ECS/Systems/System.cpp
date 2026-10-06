/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** System
*/

#include "System.hpp"

System::System()
{
    _dt = 0.1;
    _name = "undefined";
}

System::~System() {}

void System::update() {}

void System::addComponent(std::shared_ptr<Component> const &component)
{
    _components.insert(_components.size(), component);
}

SparseArray<Component> System::getComponents() const
{
    return _components;
}

std::shared_ptr<Component> System::getComponent(size_t idx) const
{
    if (idx >= _components.size())
        throw std::out_of_range("System::getComponent");
    if (_components.at(idx) == nullptr)
        throw std::out_of_range("System::getComponent");
    return _components.at(idx);
}

void System::info() const
{
    std::cout << _name << std::endl;
    for (const auto &component : _components)
        std::cout << "\t" << typeid(*component.second).name() << std::endl;
}

void System::setDeltaTime(float dt) {
    _dt = dt;
}

float System::getDeltaTime() const {
    return _dt;
}

void System::setRefTime(std::chrono::system_clock::time_point refTime) {
    _refTime = refTime;
}

std::chrono::system_clock::time_point System::getRefTime() const {
    return _refTime;
}
