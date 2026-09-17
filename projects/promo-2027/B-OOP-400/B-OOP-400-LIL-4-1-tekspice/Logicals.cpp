/*
** EPITECH PROJECT, 2024
** Logicals.cpp
** File description:
** Logicals
*/

#include "components/And.hpp"
#include "components/Or.hpp"
#include "components/Xor.hpp"
#include "components/Not.hpp"
#include "components/Nand.hpp"
#include "components/Nor.hpp"
#include "components/Xnor.hpp"

#include "Factory.hpp"

void nts::ComponentFactory::addLogicals() {
    factory["and"] = []() {return std::make_unique<ComponentAnd>();};
    factory["or"] = []() {return std::make_unique<ComponentOr>();};
    factory["xor"] = []() {return std::make_unique<ComponentXor>();};
    factory["not"] = []() {return std::make_unique<ComponentNot>();};
    factory["nand"] = []() {return std::make_unique<ComponentNand>();};
    factory["nor"] = []() {return std::make_unique<ComponentNor>();};
    factory["xnor"] = []() {return std::make_unique<ComponentXnor>();};
}
