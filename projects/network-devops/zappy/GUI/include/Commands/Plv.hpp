/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** plv.hpp
*/

#ifndef PLV_HPP_
#define PLV_HPP_

#include "Cmd.hpp"

class Plv : public Cmd {
    public:
        Plv();
        ~Plv();
        void execute(Renderer &gui) override;
    private:
};


#endif /* !PLV_HPP_ */