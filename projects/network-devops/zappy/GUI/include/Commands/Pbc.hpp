/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pbc.hpp
*/

#ifndef PBC_HPP_
#define PBC_HPP_

#include "Cmd.hpp"

class Pbc : public Cmd {
    public:
        Pbc();
        ~Pbc();

        void execute(Renderer &gui) override;

    private:
};

#endif /* !PBC_HPP_ */