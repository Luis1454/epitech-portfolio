/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** msz.hpp
*/

#ifndef MSZ_HPP_
#define MSZ_HPP_

#include "Cmd.hpp"

class Msz : public Cmd {
    public:
        Msz();
        ~Msz();

        void execute(Renderer &gui) override;

    private:
};
#endif /* !MSZ_HPP_ */