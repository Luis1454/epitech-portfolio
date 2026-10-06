/*
** EPITECH PROJECT, 2024
** 4001.hpp
** File description:
** 4001
*/

#ifndef PB_4001_HPP_
#define PB_4001_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4001 : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !PB_4001_HPP_ */
