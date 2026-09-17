/*
** EPITECH PROJECT, 2024
** Xnor.hpp
** File description:
** Xnor
*/

#ifndef Xnor_HPP_
#define Xnor_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentXnor : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !Xnor_HPP_ */
