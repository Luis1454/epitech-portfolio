/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** sbp.hpp
*/

#ifndef SBP_HPP_
#define SBP_HPP_

#include "Cmd.hpp"

class Sbp : public Cmd {
    public:
        Sbp();
        ~Sbp();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !SBP_HPP_ */