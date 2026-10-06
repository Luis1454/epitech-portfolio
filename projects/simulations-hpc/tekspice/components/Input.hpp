/*
** EPITECH PROJECT, 2024
** Input.hpp
** File description:
** Input
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentInput : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !INPUT_HPP_ */
