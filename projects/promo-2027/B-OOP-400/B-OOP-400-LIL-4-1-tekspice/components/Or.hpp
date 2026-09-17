/*
** EPITECH PROJECT, 2024
** Or.hpp
** File description:
** Or
*/

#ifndef Or_HPP_
#define Or_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentOr : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !Or_HPP_ */
