/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Cmd.hpp
*/

#ifndef CMD_HPP_
#define CMD_HPP_

#include <iostream>
#include <string>
#include <vector>
#include <functional>
#include <map>
#include <sstream>
#include <memory>
#include "SFML/Graphics.hpp"
#include "../Renderer.hpp"

class Renderer;

class Cmd {
    public:
        Cmd();
        ~Cmd();

        static std::vector<std::shared_ptr<Cmd>> split(const std::string &request);
        static std::shared_ptr<Cmd> getCommand(std::vector<std::string> args);

        void setArgs(std::vector<std::string> args);
        std::vector<std::string> getArgs();

        void setName(std::string name);
        std::string getName();

        virtual void execute(Renderer &gui);

    private:
        std::string _name;
        std::vector<std::string> _args;
};

#endif /* !CMD_HPP_ */
