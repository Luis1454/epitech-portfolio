/*
** EPITECH PROJECT, 2024
** Pre4013.hpp
** File description:
** Pre4013
*/

#ifndef PRE4013_HPP_
#define PRE4013_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4013 : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
    };
}

#endif /* !PRE4013_HPP_ */
