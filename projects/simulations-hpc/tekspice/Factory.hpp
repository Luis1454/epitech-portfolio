/*
** EPITECH PROJECT, 2024
** Factory.hpp
** File description:
** Factory
*/

#ifndef FACTORY_HPP_
#define FACTORY_HPP_

#include <map>
#include <memory>
#include <functional>

#include "AComponent.hpp"

namespace nts {

    const std::vector<std::string> specials =
        {"input", "output", "clock", "true", "false"};
    const std::vector<std::string> logicals =
        {"and", "or", "xor", "not", "nand", "nor", "xnor"};
    const std::vector<std::string> prebuilt =
        {"4001", "4008", "4011", "4013", "4017","4030", "4040",
        "4069", "4071", "4094", "4514", "4801", "2716"};

    class ComponentFactory {
        public:
            ComponentFactory();
            ~ComponentFactory() = default;
            void addSpecials();
            void addLogicals();
            void addPrebuilts();


            std::unique_ptr<nts::AComponent> createComponent(const std::string &type) const {
                auto it = factory.find(type);
                if (it == factory.end())
                    return nullptr;
                return it->second();
            }

        private:
            std::map<std::string, std::function<std::unique_ptr<nts::AComponent>()>> factory = {};
    };
}

#endif /* !FACTORY_HPP_ */
