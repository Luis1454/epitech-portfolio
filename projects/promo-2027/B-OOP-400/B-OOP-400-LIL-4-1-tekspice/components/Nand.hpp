/*
** EPITECH PROJECT, 2024
** Nand.hpp
** File description:
** Nand
*/

#ifndef Nand_HPP_
#define Nand_HPP_

#include "../AComponent.hpp"

namespace nts {
    class ComponentNand : public AComponent {
        public:
            nts::Tristate compute(std::size_t pin) override;
    };
}

#endif /* !Nand_HPP_ */
