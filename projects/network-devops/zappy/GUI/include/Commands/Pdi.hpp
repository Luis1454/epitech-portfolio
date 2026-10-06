/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pdi.hpp
*/

#ifndef PDI_HPP_
#define PDI_HPP_

#include "Cmd.hpp"

class Pdi : public Cmd {
    public:
        Pdi();
        ~Pdi();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !PDI_HPP_ */