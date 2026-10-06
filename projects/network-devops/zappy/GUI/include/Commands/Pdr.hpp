/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pdr.hpp
*/

#ifndef PDR_HPP_
#define PDR_HPP_

#include "Cmd.hpp"

class Pdr : public Cmd {
    public:
        Pdr();
        ~Pdr();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !PDR_HPP_ */