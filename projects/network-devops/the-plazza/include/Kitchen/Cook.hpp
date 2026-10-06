/*
** EPITECH PROJECT, 2024
** Cook.hpp
** File description:
** Cook
*/

#ifndef COOK_HPP_
    #define COOK_HPP_


    #include <mutex>
    #include <queue>
    #include <vector>
    #include <thread>
    #include <chrono>
    #include <fstream>
    #include <iostream>
    #include <unordered_map>
    #include <condition_variable>

    #include "Stock.hpp"

class Cook {
    public:
        Cook();
        Cook(int nbCooks, int pizzaId, int nbPizza, int sizeId, Stock &stock, std::mutex &stockMtx, int &nbPizzaCook);
        ~Cook();
        void prepare(Stock &stock, int pizzaId);
    private:
        int _nbCooks;
        int _pizzaId;
        int _nbPizza;
        int _sizeId;
};

#endif /* !COOK_HPP_ */
