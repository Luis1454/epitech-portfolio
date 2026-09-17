/*
** EPITECH PROJECT, 2024
** Output.cpp
** File description:
** Output
*/

#ifndef Output_HPP_
#define Output_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentOutput : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !Output_HPP_ */
