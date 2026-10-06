/*
** EPITECH PROJECT, 2024
** Pre4081.hpp
** File description:
** Pre4081
*/

#ifndef PRE4081_HPP_
#define PRE4081_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4081 : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
    };
};

#endif /* !PRE4081_HPP_ */
