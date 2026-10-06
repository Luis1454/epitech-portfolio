/*
** EPITECH PROJECT, 2024
** Xor.hpp
** File description:
** Xor
*/

#ifndef Xor_HPP_
#define Xor_HPP_

#include "../AComponent.hpp"


namespace nts {
    class ComponentXor : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !Xor_HPP_ */
