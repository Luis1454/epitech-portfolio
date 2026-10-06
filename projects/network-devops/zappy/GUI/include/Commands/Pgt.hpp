/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pgt.hpp
*/

#ifndef PGT_HPP_
#define PGT_HPP_

#include "Cmd.hpp"

class Pgt : public Cmd  {
    public:
        Pgt();
        ~Pgt();

        void execute(Renderer &gui) override;

    private:
};

#endif /* !PGT_HPP_ */