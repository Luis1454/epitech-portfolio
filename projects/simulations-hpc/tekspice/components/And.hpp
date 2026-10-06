/*
** EPITECH PROJECT, 2024
** And.hpp
** File description:
** And
*/

#ifndef And_HPP_
#define And_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentAnd : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !And_HPP_ */
