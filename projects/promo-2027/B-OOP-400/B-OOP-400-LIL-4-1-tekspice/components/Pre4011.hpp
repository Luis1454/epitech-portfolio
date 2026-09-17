/*
** EPITECH PROJECT, 2024
** Pre4011.hpp
** File description:
** Pre4011
*/

#ifndef PRE4011_HPP_
#define PRE4011_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4011 : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
    };
};

#endif /* !PRE4011_HPP_ */
