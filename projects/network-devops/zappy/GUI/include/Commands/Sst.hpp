/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** sst.hpp
*/

#ifndef SST_HPP_
#define SST_HPP_

#include "Cmd.hpp"

class Sst : public Cmd {
    public:
        Sst();
        ~Sst();
        void execute(Renderer &gui) override;
    private:
};


#endif /* !SST_HPP_ */