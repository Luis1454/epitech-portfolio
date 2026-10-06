/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** ppo.hpp
*/

#ifndef PPO_HPP_
#define PPO_HPP_

#include "Cmd.hpp"
#include "../Renderer.hpp"

class Ppo : public Cmd {
    public:
        Ppo();
        ~Ppo();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !PPO_HPP_ */