/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Pizza
*/

#include "../../include/Pizzas/Pizza.hpp"

Pizza::Pizza() {
    _ingredients = {};
    _type = UNDEFINED;
    _size = UNDEFINED;
    _timeToCook = UNDEFINED;
    _isCooked = false;
}

Pizza::~Pizza()
{
}

std::map<pizza::Ingredient, int> Pizza::getIngredients() const
{
    return _ingredients;
}

int Pizza::getType() const
{
    return _type;
}

int Pizza::getSize() const
{
    return _size;
}

std::size_t Pizza::getTimeToCook() const
{
    return _timeToCook;
}

bool Pizza::isCooked() const
{
    return _isCooked;
}

void Pizza::setIngredients(std::map<pizza::Ingredient, int> ingredients)
{
    _ingredients = ingredients;
}

void Pizza::setType(pizza::PizzaType type)
{
    _type = type;
}

void Pizza::setSize(pizza::PizzaSize size)
{
    _size = size;
}

void Pizza::setCookTime(std::size_t timeToCook)
{
    _timeToCook = timeToCook;
}

void Pizza::setState(bool isCooked)
{
    _isCooked = isCooked;
}

bool Pizza::canBeCooked()
{
    return !_isCooked;
}

void Pizza::prepare(Stock &stock)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(_timeToCook));
    _isCooked = true;
    for (auto &ingredient : _ingredients) {
        if (ingredient.first == pizza::Ingredient::Dough)
            stock.setDough(stock.getDough() - 1);
        if (ingredient.first == pizza::Ingredient::Tomato)
            stock.setTomato(stock.getTomato() - 1);
        if (ingredient.first == pizza::Ingredient::Gruyere)
            stock.setGruyere(stock.getGruyere() - 1);
        if (ingredient.first == pizza::Ingredient::Ham)
            stock.setHam(stock.getHam() - 1);
        if (ingredient.first == pizza::Ingredient::Mushrooms)
            stock.setMushrooms(stock.getMushrooms() - 1);
        if (ingredient.first == pizza::Ingredient::Steak)
            stock.setSteak(stock.getSteak() - 1);
        if (ingredient.first == pizza::Ingredient::Eggplant)
            stock.setEggplant(stock.getEggplant() - 1);
        if (ingredient.first == pizza::Ingredient::GoatCheese)
            stock.setGoatCheese(stock.getGoatCheese() - 1);
        if (ingredient.first == pizza::Ingredient::ChiefLove)
            stock.setChiefLove(stock.getChiefLove() - 1);
    }
}

