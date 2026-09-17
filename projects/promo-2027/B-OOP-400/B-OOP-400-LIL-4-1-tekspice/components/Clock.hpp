/*
** EPITECH PROJECT, 2024
** Clock.hpp
** File description:
** Clock
*/

#ifndef CLOCK_HPP_
#define CLOCK_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentClock : public AComponent {
        public:
            nts::Tristate compute(std::size_t tick) override;
            void setPin(std::size_t pin, nts::Tristate value) override;
        private:
            std::size_t _init = 0;
    };
}

#endif /* !CLOCK_HPP_ */
