/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Order
*/

#ifndef PIZZA_HPP_
    #define PIZZA_HPP_

    #include <map>
    #include <mutex>
    #include <vector>
    #include <thread>
    #include <chrono>
    #include <iostream>
    #include <algorithm>
    #include <unordered_map>
    #include <condition_variable>

    #include "../Kitchen/Stock.hpp"

#define UNDEFINED -1

namespace pizza
{
    enum PizzaType {
        Regina = 1,
        Margarita = 2,
        Americana = 4,
        Fantasia = 8
    };

    static const std::unordered_map<PizzaType, std::string> pizzaTypeString = {
        {PizzaType::Regina, "Regina"},
        {PizzaType::Margarita, "Margarita"},
        {PizzaType::Americana, "Americana"},
        {PizzaType::Fantasia, "Fantasia"}
    };

    enum PizzaSize {
        S = 1,
        M = 2,
        L = 4,
        XL = 8,
        XXL = 16
    };

    static const std::unordered_map<PizzaSize, std::string> pizzaSizeString = {
        {PizzaSize::S, "S"},
        {PizzaSize::M, "M"},
        {PizzaSize::L, "L"},
        {PizzaSize::XL, "XL"},
        {PizzaSize::XXL, "XXL"}
    };

    enum Ingredient {
        Dough = 0,
        Tomato = 1,
        Gruyere = 2,
        Ham = 3,
        Mushrooms = 4,
        Steak = 5,
        Eggplant = 6,
        GoatCheese = 7,
        ChiefLove = 8,
    };
}

class Pizza {
    public:
        Pizza();
        ~Pizza();

        virtual bool canBeCooked();
        virtual void prepare(Stock &stock);

        virtual void setIngredients(std::map<pizza::Ingredient, int> ingredients);
        virtual void setCookTime(std::size_t timeToCook);
        virtual void setState(bool isCooked);
        virtual void setSize(pizza::PizzaSize size);
        virtual void setType(pizza::PizzaType type);

        virtual std::map<pizza::Ingredient, int> getIngredients() const;
        virtual int getType() const;
        virtual int getSize() const;
        virtual std::size_t getTimeToCook() const;
        virtual bool isCooked() const;

    private:
        std::map<pizza::Ingredient, int> _ingredients;
        std::size_t _timeToCook;
        int _size;
        int _type;
        bool _isCooked;
};

#endif /* !PIZZA_HPP_ */
