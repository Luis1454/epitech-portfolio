/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** seg.hpp
*/

#ifndef SEG_HPP_
#define SEG_HPP_

#include "Cmd.hpp"

class Seg : public Cmd {
    public:
        Seg();
        virtual ~Seg();
        virtual void execute(Renderer &gui) override;
    private:
};

#endif /* !SEG_HPP_ */
