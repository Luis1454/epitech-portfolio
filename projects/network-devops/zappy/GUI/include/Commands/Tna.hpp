/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** tna.hpp
*/

#ifndef TNA_HPP_
#define TNA_HPP_

#include "Cmd.hpp"

class Tna : public Cmd {
    public:
        Tna();
        ~Tna();
        void execute(Renderer &gui) override;

    private:
};

#endif /* !TNA_HPP_ */