/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** Parser
*/

#ifndef PARSER_HPP_
    #define PARSER_HPP_

#include "Handling.hpp"
#include <fstream>

class Parser {
    public:
        Parser();
        ~Parser();
        int parse(int ac, char **av);
};

#endif /* !PARSER_HPP_ */
