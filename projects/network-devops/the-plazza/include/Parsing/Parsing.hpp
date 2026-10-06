/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Parsing
*/

#ifndef PARSING_HPP_
    #define PARSING_HPP_

    #include <mutex>
    #include <vector>
    #include <thread>
    #include <chrono>
    #include <sstream>
    #include <iostream>
    #include <algorithm>
    #include <condition_variable>

    #include "../Pizzas/Pizza.hpp"

class Shell {
    public:
        std::string TYPE;
        std::string SIZE;
        std::string NUMBER;
        size_t NUMBER_INT;
        std::string lowerType() const;
};

class Parsing {
    public:
        Parsing();
        ~Parsing();
        void parseArguments(int ac, char **av);
        void parseShell(std::string input);
        bool isValidType(const std::string& type);
        bool isValidSize(const std::string& size);
        bool isValidNumber(const std::string& number);
        Shell parseCommand(std::string input);
        float getCoockingTime();
        int getNumberOfCooks();
        float getRestockTime();
        std::vector<Shell> getShell();

    private:
        float _cookingTime;
        int _numberOfCooks;
        float _restockTime;
        std::vector<Shell>  _shell;
};

#endif /* !PARSING_HPP_ */
