/*
** EPITECH PROJECT, 2024
** Magarita.cpp
** File description:
** Magarita
*/

#include "../../include/Pizzas/Margarita.hpp"

Margarita::Margarita()
{
    setIngredients((std::map<pizza::Ingredient, int>) {
        {pizza::Ingredient::Dough, 1},
        {pizza::Ingredient::Tomato, 1},
        {pizza::Ingredient::Gruyere, 1},
    });
    setType(pizza::PizzaType::Regina);
    setSize(pizza::PizzaSize::M);
    setCookTime(2);
}

Margarita::~Margarita()
{
}
