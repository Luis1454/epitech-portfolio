/*
** EPITECH PROJECT, 2024
** Americana.cpp
** File description:
** Americana
*/

#include "../../include/Pizzas/Americana.hpp"

Americana::Americana()
{
    setIngredients((std::map<pizza::Ingredient, int>) {
        {pizza::Ingredient::Dough, 1},
        {pizza::Ingredient::Tomato, 1},
        {pizza::Ingredient::Gruyere, 1},
        {pizza::Ingredient::Steak, 1},
    });
    setType(pizza::PizzaType::Regina);
    setSize(pizza::PizzaSize::M);
    setCookTime(2);
}

Americana::~Americana()
{
}
