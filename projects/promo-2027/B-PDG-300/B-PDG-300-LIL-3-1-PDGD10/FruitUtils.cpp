/*
** EPITECH PROJECT, 2024
** FruitUtils.cpp
** File description:
** FruitUtils
*/

#include "FruitUtils.hpp"
#include "IFruit.hpp"

void FruitUtils::sort(FruitBox &box, FruitBox &lemonBox, FruitBox &limeBox, FruitBox &bananaBox, FruitBox &coconutBox)
{
    node_t *tmp = box.head();
    std::string name;

    while (tmp) {
        name = typeid(*tmp->data).name();
        name == "lemon" ? lemonBox.pushFruit(tmp->data) : 0;
        name == "lime" ? limeBox.pushFruit(tmp->data) : 0;
        name == "banana" ? bananaBox.pushFruit(tmp->data) : 0;
        name == "coconut" ? coconutBox.pushFruit(tmp->data) : 0;
        tmp = tmp->next;
    }
}
