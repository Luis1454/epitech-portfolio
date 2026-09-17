/*
** EPITECH PROJECT, 2024
** Pre4030.hpp
** File description:
** Pre4030
*/

#ifndef PRE4030_HPP_
#define PRE4030_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4030 : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
    };
};

#endif /* !PRE4030_HPP_ */
