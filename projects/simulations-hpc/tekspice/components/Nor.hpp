/*
** EPITECH PROJECT, 2024
** Nor.hpp
** File description:
** Nor
*/

#ifndef Nor_HPP_
#define Nor_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentNor : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !Nor_HPP_ */
