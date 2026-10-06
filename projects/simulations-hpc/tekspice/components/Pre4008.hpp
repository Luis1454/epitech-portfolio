/*
** EPITECH PROJECT, 2024
** Pre4008.hpp
** File description:
** Pre4008
*/

#ifndef PRE4008_HPP_
#define PRE4008_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4008 : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
    };
};

#endif /* !PRE4008_HPP_ */
