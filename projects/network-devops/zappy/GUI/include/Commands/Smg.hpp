/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** smg.hpp
*/

#ifndef SMG_HPP_
#define SMG_HPP_

#include "Cmd.hpp"

class Smg : public Cmd  {
    public:
        Smg();
        ~Smg();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !SMG_HPP_ */