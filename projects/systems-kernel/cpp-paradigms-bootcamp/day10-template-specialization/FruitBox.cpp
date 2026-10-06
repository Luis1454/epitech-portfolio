/*
** EPITECH PROJECT, 2024
** FruitBox.cpp
** File description:
** FruitBox
*/

#include "FruitBox.hpp"

node_t *FruitBox::head() const
{
    return _head;
}

std::ostream &operator<<(std::ostream &os, const FruitBox &box)
{
    node_t *tmp = box.head();

    os << "[";
    for (; tmp != nullptr; tmp = tmp->next) {
        os << "[name: \"" << tmp->data->getName() << "\", vitamins: " << tmp->data->getVitamins()
        << ", peeled: " << (tmp->data->isPeeled() ? "true" : "false") << "]";
        if (tmp->next != nullptr)
            os << ", ";
    }
    os << "]";
    return os;
}

unsigned int FruitBox::getSize() const
{
    return _size;
}

unsigned int FruitBox::nbFruits() const
{
    unsigned int nb = 0;

    for (node_t *tmp = _head; tmp != nullptr; tmp = tmp->next)
        nb++;
    return nb;
}

bool FruitBox::pushFruit(IFruit *fruit)
{
    node_t *tmp = _head;

    if (nbFruits() >= getSize() || fruit == nullptr)
        return false;
    if (_head == nullptr) {
        _head = new node_t;
        _head->data = fruit;
        _head->next = nullptr;
        return true;
    }
    for (; tmp->next != nullptr; tmp = tmp->next);
    tmp->next = new node_t;
    tmp->next->data = fruit;
    tmp->next->next = nullptr;
    return true;
}

IFruit *FruitBox::popFruit()
{
    node_t *tmp = _head;
    IFruit *fruit = nullptr;

    if (_head == nullptr)
        return nullptr;
    fruit = (IFruit *)tmp->data;
    _head = _head->next;
    delete tmp;
    return fruit;
}

FruitBox::FruitBox(int size)
{
    _size = size;
    _head = nullptr;
}

FruitBox::~FruitBox()
{
    node_t *tmp = _head;
    node_t *prev = nullptr;

    for (; tmp != nullptr; tmp = tmp->next) {
        if (prev != nullptr)
            delete prev;
        delete tmp->data;
        prev = tmp;
    }
    if (prev != nullptr)
        delete prev;
}
