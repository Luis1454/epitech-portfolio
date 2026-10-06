/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** pin.hpp
*/

#ifndef PIN_HPP_
#define PIN_HPP_

#include "Cmd.hpp"

class Pin : public Cmd {
    public:
        Pin();
        ~Pin();
        void execute(Renderer &gui) override;
    private:
};

#endif /* !PIN_HPP_ */