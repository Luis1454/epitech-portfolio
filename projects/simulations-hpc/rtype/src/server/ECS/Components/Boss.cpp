/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** Boss
*/

#include "Boss.hpp"

void Boss::dropEntity(int idx) {
    Component::dropEntity(idx);
}

void Boss::info() const {
    if (this == nullptr) {
        std::cout << "Boss not initialized (nullptr)" << std::endl;
        return;
    }

    std::cout << "Boss (" << this->getEntities().size() << ")" << std::endl;
    for (auto &e : this->getEntities())
        std::cout << "  - " << e.first << std::endl;
}
