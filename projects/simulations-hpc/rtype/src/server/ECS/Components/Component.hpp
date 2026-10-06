/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Component
*/

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "../Sparse.hpp"
#include "../Entities/Entity.hpp"
#include <unordered_map>
#include <vector>
#include <iostream>

class Component {
    public:
        Component() = default;
        virtual ~Component() = default;

        void addEntity(int idx, std::shared_ptr<Entity> entity);

        SparseArray<Entity> getEntities() const;
        std::vector<int> getIDs() const;

        std::shared_ptr<Entity> getEntity(int idx);

        virtual void info() const = 0;
        virtual void dropEntity(int idx);

        auto begin() { return _entities.begin(); }
        auto end() { return _entities.end(); }
        auto begin() const { return _entities.begin(); }
        auto end() const { return _entities.end(); }

    protected:
        std::unordered_map<int, std::shared_ptr<Entity>> _entities;
};

#endif /* !COMPONENT_HPP_ */
