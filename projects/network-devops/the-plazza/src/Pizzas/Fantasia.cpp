/*
** EPITECH PROJECT, 2024
** Fantasia.cpp
** File description:
** Fantasia
*/

#include "../../include/Pizzas/Fantasia.hpp"

Fantasia::Fantasia()
{
    setIngredients((std::map<pizza::Ingredient, int>) {
        {pizza::Ingredient::Dough, 1},
        {pizza::Ingredient::Tomato, 1},
        {pizza::Ingredient::Eggplant, 1},
        {pizza::Ingredient::GoatCheese, 1},
        {pizza::Ingredient::ChiefLove, 1}
    });
    setType(pizza::PizzaType::Regina);
    setSize(pizza::PizzaSize::M);
    setCookTime(2);
}

Fantasia::~Fantasia()
{
}
