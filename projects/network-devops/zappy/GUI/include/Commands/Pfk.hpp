/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pfk.hpp
*/

#ifndef PFK_HPP_
#define PFK_HPP_ 

#include "Cmd.hpp"

class Pfk : public Cmd {
    public:
        Pfk();
        ~Pfk();

        void execute(Renderer &gui) override;

    private:
};

#endif /* !PFK_HPP_ */