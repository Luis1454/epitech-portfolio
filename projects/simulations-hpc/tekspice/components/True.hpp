/*
** EPITECH PROJECT, 2024
** True.hpp
** File description:
** True
*/

#ifndef TRUE_HPP_
#define TRUE_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentTrue : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !TRUE_HPP_ */
