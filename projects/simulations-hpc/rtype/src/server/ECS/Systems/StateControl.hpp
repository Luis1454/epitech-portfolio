/*
** EPITECH PROJECT, 2025
** B-CPP-500-LIL-5-2-rtype-salman.rezki
** File description:
** StateControl
*/

#ifndef STATECONTROL_HPP_
#define STATECONTROL_HPP_

#include "System.hpp"

class StateControl : public System {
    public:
        StateControl();
        ~StateControl() = default;

        void update() override;

    protected:
};

#endif /* !STATECONTROL_HPP_ */
