/*
** EPITECH PROJECT, 2024
** PizzaTools.hpp
** File description:
** PizzaTools
*/

#ifndef PIZZA_TOOLS_HPP_
    #define PIZZA_TOOLS_HPP_

    #include <iostream>

    #include "../Pizzas/Pizza.hpp"

class PizzaTools {
    public:
        PizzaTools();
        ~PizzaTools();

        std::size_t getPizzaNumber(pizza::PizzaType pizza);
        std::string getPizzaStringWithNumber(std::size_t pizza);
        int recupNumPizza(std::string pizza);
        std::size_t getPizzaSize(pizza::PizzaSize size);
        std::string getPizzaSizeWithNumber(std::size_t size);
        int recupNumSize(std::string size);

    protected:
        pizza::PizzaType _type;
        pizza::PizzaSize _size;
        float _cookingTime;
        bool _cooked;
        std::vector<std::string> _ingredients;
        std::chrono::time_point<std::chrono::system_clock> _orderTime;
};

#endif /* !PIZZA_HPP_ */