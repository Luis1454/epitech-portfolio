/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** RigidBody
*/

#include "RigidBody.hpp"

void RigidBody::info() const {
    std::cout << "RigidBody (" << _body.size() << "):" << std::endl;
    for (auto &it : _body)
        std::cout << "  " << it.first << " -> " << it.second.left << ", " << it.second.top << ", "
            << it.second.width << ", " << it.second.height << std::endl;
}

void RigidBody::dropEntity(int idx) {
    Component::dropEntity(idx);

    _body.erase(idx);
}

std::vector<std::pair<int, int>> RigidBody::intersect(std::vector<int> others) const {
    std::vector<std::pair<int, int>> ret;

    for (auto &it : _body)
        for (auto &o : others) {
            if (it.first == o)
                continue;
            if (it.second.intersects(_body.at(o)))
                ret.push_back({it.first, o});
        }
    return ret;
}

void RigidBody::setBody(std::size_t idx, const sf::FloatRect &rect) {
    _body[idx] = rect;
}

sf::FloatRect RigidBody::getBody(std::size_t idx) const {
    return _body.at(idx);
}