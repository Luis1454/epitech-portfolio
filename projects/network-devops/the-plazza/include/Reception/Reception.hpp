/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Reception
*/

#ifndef RECEPTION_HPP_
    #define RECEPTION_HPP_

    #include <mutex>
    #include <vector>
    #include <thread>
    #include <chrono>
    #include <iostream>
    #include <condition_variable>

    #include "../Utils/Utils.hpp"
    #include "../Utils/Timer.hpp"
    #include "../Error/Error.hpp"
    #include "../Pizzas/Pizza.hpp"
    #include "../Utils/Sender.hpp"
    #include "../Utils/Reciever.hpp"
    #include "../Kitchen/Kitchen.hpp"
    #include "../Parsing/Parsing.hpp"
    #include "../Utils/PizzaTools.hpp"

class kitchenPreparation {
    public:
        std::vector<std::string> _command;
        std::vector<std::string> _size;
        std::vector<int> _number;
        std::vector<std::vector<int>> _pipefd;
        std::vector<std::vector<int>> _pipefd2;
        std::vector<int> id;
    private:
};

class Reception {
    public:
        Reception();
        Reception(float cookingTime, int numberOfCooks, float restockTime);
        ~Reception();
        void startReception();
        void shell();
        std::size_t nbKitchensToCreate(std::size_t nbCooks, std::size_t nbPizza);
        void interpretCommand(const std::string& input);
        void sendToKitchen(const kitchenPreparation& kitchen, int index);
        void receiveFromKitchen(const kitchenPreparation& kitchen, int index);
        std::vector<kitchenPreparation> createAllKitchens(std::vector<Shell>& shells);
        void createPipeLink(kitchenPreparation& kitchen, int index);

    private:
        Parsing _parsing;
        Timer _timer;
        float _cookingTime;
        float _restockTime;
        std::size_t _numberOfCooks;
        Utils::Pipe pipe_Utils;
        Utils::Fork fork_Utils;
        std::size_t _nbKitchens;
        std::vector<kitchenPreparation> _kitchens;
};


#endif /* !RECEPTION_HPP_ */
