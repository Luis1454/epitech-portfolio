/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** sgt.hpp
*/

#ifndef SGT_HPP_
#define SGT_HPP_

#include "Cmd.hpp"

class Sgt : public Cmd {
    public:
        Sgt();
        ~Sgt();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !SGT_HPP_ */
