/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Kitchen
*/

#ifndef KITCHEN_HPP_
    #define KITCHEN_HPP_

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
    #include "ThreadPool.hpp"
    #include "../Pizzas/Pizza.hpp"
    #include "../Utils/Sender.hpp"
    #include "../Utils/Message.hpp"
    #include "../Utils/Reciever.hpp"
    #include "../Utils/PizzaTools.hpp"
    #include "../Reception/Reception.hpp"

class Kitchen {
    public:
        Kitchen(float cookingTime, int numberOfCooks, float restockTime, std::vector<int> pipefd);
        ~Kitchen();
        void sendToReception(std::string msg);
        void startKitchen(std::vector<int> pipefd);
        void revieveFromReception(std::vector<int> pipefd);
        void writeInLogFile(std::string pizza, std::string size, std::string number, std::string kitchen);
        static void createCook(int nbCooks, int _PizzaId, int _NumberPizza, int _SizeId, Stock &stock, std::mutex &stockMtx, int &nbPizzaCook);

        std::string readMessage(std::vector<int> pipefd);

    private:
        int _NumberPizza;
        int _KitchensId;
        int _PizzaId;
        int _SizeId;
        float _cookingTime;
        int _numberOfCooks;
        float _restockTime;
        std::vector<int> _secondpipefd;
        ThreadPool _pool;
        Stock stock;
};

#endif /* KITCHEN_HPP_ */
