/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** ebo.hpp
*/

#ifndef EBO_HPP_
#define EBO_HPP_

#include "Cmd.hpp"

class Ebo : public Cmd {
    public:
        Ebo();
        ~Ebo();

        void execute(Renderer &gui) override;

    private:
};

#endif /* !EBO_HPP_ */
