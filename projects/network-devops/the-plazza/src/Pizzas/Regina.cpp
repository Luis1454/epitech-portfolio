/*
** EPITECH PROJECT, 2024
** Regina.cpp
** File description:
** Regina
*/

#include "../../include/Pizzas/Regina.hpp"
#include "../../include/Pizzas/Pizza.hpp"

Regina::Regina()
{
    setIngredients((std::map<pizza::Ingredient, int>) {
        {pizza::Ingredient::Dough, 1},
        {pizza::Ingredient::Ham, 1},
        {pizza::Ingredient::Tomato, 1},
        {pizza::Ingredient::Gruyere, 1},
        {pizza::Ingredient::Mushrooms, 1}
    });

    setType(pizza::PizzaType::Regina);
    setSize(pizza::PizzaSize::M);
    setCookTime(2);
}

Regina::~Regina()
{
}
