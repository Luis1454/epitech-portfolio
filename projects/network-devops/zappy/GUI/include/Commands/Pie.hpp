/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pie.hpp
*/

#ifndef PIE_HPP_
#define PIE_HPP_

#include "Cmd.hpp"

class Pie : public Cmd {
    public:
        Pie();
        ~Pie();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !PIE_HPP_ */