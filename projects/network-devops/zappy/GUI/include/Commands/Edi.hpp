/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** edi.hpp
*/

#ifndef EDI_HPP_
#define EDI_HPP_

#include "Cmd.hpp"

class Edi : public Cmd {
    public:
        Edi();
        virtual ~Edi();

        virtual void execute(Renderer &gui) override;

    private:
        std::vector<std::string> _args;
};

#endif /* !EDI_HPP_ */
