/*
** EPITECH PROJECT, 2024
** False.hpp
** File description:
** False
*/

#ifndef False_HPP_
#define False_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentFalse : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !False_HPP_ */
