/*
** EPITECH PROJECT, 2024
** Specials.cpp
** File description:
** Specials
*/

#include "Factory.hpp"

#include "components/Input.hpp"
#include "components/Output.hpp"
#include "components/Clock.hpp"
#include "components/True.hpp"
#include "components/False.hpp"

void nts::ComponentFactory::addSpecials() {
    factory["input"] = []() {return std::make_unique<ComponentInput>();};
    factory["output"] = []() {return std::make_unique<ComponentOutput>();};
    factory["clock"] = []() {return std::make_unique<ComponentClock>();};
    factory["true"] = []() {return std::make_unique<ComponentTrue>();};
    factory["false"] = []() {return std::make_unique<ComponentFalse>();};
}
