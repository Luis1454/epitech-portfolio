/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** enw.hpp
*/

#ifndef ENW_HPP_
#define ENW_HPP_

#include "Cmd.hpp"

class Enw : public Cmd {
    public:
        Enw();
        ~Enw();

        void execute(Renderer &gui) override;

    private:
};

#endif /* !ENW_HPP_ */
