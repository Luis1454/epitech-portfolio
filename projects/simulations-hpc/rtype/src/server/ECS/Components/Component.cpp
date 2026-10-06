/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Component
*/

#include "Component.hpp"
#include <iostream>

void Component::addEntity(int idx, std::shared_ptr<Entity> entity)
{
    if (this == nullptr)
        return;
    _entities.insert_or_assign(idx, entity);
}

void Component::dropEntity(int idx)
{
    if (this == nullptr)
        return;
    _entities.erase(idx);
}

SparseArray<Entity> Component::getEntities() const
{
    SparseArray<Entity> output;

    if (this == nullptr)
        return output;

    for (auto &e: _entities)
        output.insert(e.first, e.second);
    return output;
}

std::vector<int> Component::getIDs() const {
    std::vector<int> output;

    if (this == nullptr)
        return output;

    for (auto &e: _entities)
        output.push_back(e.first);
    return output;
}

std::shared_ptr<Entity> Component::getEntity(int idx)
{
    if (this == nullptr)
        return nullptr;
    if (_entities.find(idx) == _entities.end())
        return nullptr;
    return _entities.at(idx);
}
