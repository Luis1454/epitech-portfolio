/*
** EPITECH PROJECT, 2024
** Not.hpp
** File description:
** Not
*/

#ifndef Not_HPP_
#define Not_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentNot : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !Not_HPP_ */
