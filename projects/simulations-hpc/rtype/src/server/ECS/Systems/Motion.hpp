/*
** EPITECH PROJECT, 2024
** rtype
** File description:
** Motion
*/

#ifndef MOTION_HPP_
#define MOTION_HPP_

#include "System.hpp"

class Motion : public System {
    public:
        Motion();
        ~Motion() = default;

        void update() override;
};

#endif /* !MOTION_HPP_ */
