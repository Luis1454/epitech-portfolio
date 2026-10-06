/*
** EPITECH PROJECT, 2024
** Icomponent.hpp
** File description:
** Icomponent
*/

#ifndef ICOMPONENT_HPP_
#define ICOMPONENT_HPP_

#include <string>
#include <vector>
#include <memory>
#include <map>

namespace nts {

    typedef std::pair<std::string, std::size_t> link_t;

    enum Tristate {
        Undefined = (-true),
        True = true,
        False = false
    };

    class IComponent
    {
        public:
            virtual ~IComponent() = default;
            virtual nts::Tristate compute(std::size_t pin) = 0;
            virtual void setName(std::string name) = 0;
            virtual void setCategory(std::string type) = 0;
            virtual void setPin(std::size_t pin, nts::Tristate state) = 0;

            virtual std::string getName() = 0;
            virtual std::string getCategory() = 0;
            virtual nts::Tristate getPin(std::size_t pin) = 0;
            virtual std::map<std::size_t, link_t> getLinks() = 0;
    };
}

#endif /* !ICOMPONENT_HPP_ */
