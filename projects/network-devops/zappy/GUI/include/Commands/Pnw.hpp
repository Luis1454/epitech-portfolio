/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Pnw.hpp
*/

#ifndef PNW_HPP_
#define PNW_HPP_

#include "Cmd.hpp"

class Pnw : public Cmd {
    public:
        Pnw();
        ~Pnw();

        void execute(Renderer &gui) override;

    private:
};

#endif /* !PNW_HPP_ */