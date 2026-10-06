/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** bct.hpp
*/

#ifndef BCT_HPP_
#define BCT_HPP_

#include "Cmd.hpp"

class Bct : public Cmd {
    public:
        Bct();
        ~Bct();

        void execute(Renderer &gui) override;

    private:
};

#endif /* !BCT_HPP_ */
