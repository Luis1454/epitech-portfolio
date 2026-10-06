/*
** EPITECH PROJECT, 2024
** Cook.cpp
** File description:
** Cook
*/

#include "../../include/Kitchen/Cook.hpp"
#include "../../include/Utils/PizzaTools.hpp"
#include "../../include/Kitchen/Stock.hpp"
#include "../../include/Pizzas/Pizza.hpp"

#include "../../include/Pizzas/Regina.hpp"
#include "../../include/Pizzas/Margarita.hpp"
#include "../../include/Pizzas/Americana.hpp"
#include "../../include/Pizzas/Fantasia.hpp"

Cook::Cook()
{
}

class PizzaFactory {
public:
    std::unique_ptr<Pizza> createPizza(int type) {
        switch (type) {
            case pizza::PizzaType::Regina:
                return std::make_unique<Regina>();
            case pizza::PizzaType::Margarita:
                return std::make_unique<Margarita>();
            case pizza::PizzaType::Americana:
                return std::make_unique<Americana>();
            case pizza::PizzaType::Fantasia:
                return std::make_unique<Fantasia>();
        }
        return nullptr;
    }
};

Cook::Cook(int nbCooks, int pizzaId, int nbPizza, int sizeId, Stock &stock, std::mutex &stockMtx, int &nbPizzaCook)
{
    _nbCooks = nbCooks;
    _pizzaId = pizzaId;
    _nbPizza = nbPizza;
    _sizeId = sizeId;

    std::shared_ptr<Pizza> pizza = std::make_shared<Pizza>();
    PizzaTools piz;
    std::string tmp = piz.getPizzaStringWithNumber(pizzaId);
    int t = 0;
    for (; t < 2; t++) {
        std::lock_guard<std::mutex> lock(stockMtx);
        if (nbPizzaCook >= nbPizza)
            return;
        prepare(stock, pizzaId);

        nbPizzaCook++;
        stockMtx.unlock();
    }
}

void Cook::prepare(Stock &stock, int pizzaId)
{
    PizzaFactory factory;
    std::shared_ptr<Pizza> pizza = factory.createPizza(pizzaId);
    pizza->prepare(stock);
}

Cook::~Cook()
{
}
