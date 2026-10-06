/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** suc.hpp
*/

#ifndef SUC_HPP_
#define SUC_HPP_

#include "Cmd.hpp"

class Suc : public Cmd {
    public:
        Suc();
        ~Suc();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !SUC_HPP_ */