/*
** EPITECH PROJECT, 2024
** Pre4069.hpp
** File description:
** Pre4069
*/

#ifndef PRE4069_HPP_
#define PRE4069_HPP_

#include "../AComponent.hpp"

namespace nts {
    class Component4069 : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
    };
};

#endif /* !PRE4069_HPP_ */
