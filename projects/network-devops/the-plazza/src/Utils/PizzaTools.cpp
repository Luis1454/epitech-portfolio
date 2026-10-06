/*
** EPITECH PROJECT, 2024
** PizzaTools.cpp
** File description:
** PizzaTools
*/

#include "../../include/Utils/PizzaTools.hpp"

PizzaTools::PizzaTools()
{
}

PizzaTools::~PizzaTools()
{
}

std::size_t PizzaTools::getPizzaNumber(pizza::PizzaType pizza)
{
    return static_cast<std::size_t>(pizza);
}

std::string PizzaTools::getPizzaStringWithNumber(std::size_t pizza)
{
    for (const auto& i : pizza::pizzaTypeString)
        if (pizza == getPizzaNumber(i.first))
            return i.second;
    return std::string("");
}

int PizzaTools::recupNumPizza(std::string pizza)
{
    std::transform(pizza.begin(), pizza.end(), pizza.begin(), ::tolower);
    pizza[0] = std::toupper(pizza[0]);

    for (const auto& i : pizza::pizzaTypeString)
        if (pizza == i.second)
            return getPizzaNumber(i.first);
    return 0;
}

std::size_t PizzaTools::getPizzaSize(pizza::PizzaSize size)
{
    return static_cast<std::size_t>(size);
}

std::string PizzaTools::getPizzaSizeWithNumber(std::size_t size)
{
    for (const auto& i : pizza::pizzaSizeString)
        if (size == getPizzaSize(i.first))
            return i.second;
    return std::string("");
}

int PizzaTools::recupNumSize(std::string size)
{
    for (const auto& i : pizza::pizzaSizeString)
        if (size == i.second)
            return getPizzaSize(i.first);
    return 0;
}
