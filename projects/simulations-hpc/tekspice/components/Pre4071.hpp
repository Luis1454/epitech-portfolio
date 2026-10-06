/*
** EPITECH PROJECT, 2024
** Pre4071.hpp
** File description:
** Pre4071
*/

#ifndef PRE4071_HPP_
#define PRE4071_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4071 : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
    };
};

#endif /* !PRE4071_HPP_ */
