/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** Register
*/

#ifndef REGISTER_HPP_
    #define REGISTER_HPP_

#include "../../graphicals/IDisplayModule.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Register {
    public:
        Register();
        ~Register();
        std::unique_ptr<IDisplayModule> Register_part(std::unique_ptr<IDisplayModule> displayModule, int key);
        void set_name_of_player(std::string name);
        std::string get_name_of_player();
        char get_key_value(int key);
        char min_to_maj(char c);
        std::string name_of_player;
};

#endif /* !REGISTER_HPP_ */
