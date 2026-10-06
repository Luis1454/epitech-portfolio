/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pex.hpp
*/

#ifndef PEX_HPP_
#define PEX_HPP_

#include "Cmd.hpp"

class Pex : public Cmd {
    public:
        Pex();
        ~Pex();
        void execute(Renderer &gui) override;
};
#endif /* !PEX_HPP_ */