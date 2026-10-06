/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pic.hpp
*/

#ifndef PIC_HPP_
#define PIC_HPP_

#include "Cmd.hpp"

class Pic : public Cmd {
    public:
        Pic();
        ~Pic();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !PIC_HPP_ */