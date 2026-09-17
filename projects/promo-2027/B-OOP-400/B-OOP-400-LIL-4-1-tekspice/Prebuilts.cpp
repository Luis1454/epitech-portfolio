/*
** EPITECH PROJECT, 2024
** Prebuilts.cpp
** File description:
** Prebuilts
*/

#include "components/Pre4001.hpp"
#include "components/Pre4008.hpp"
#include "components/Pre4011.hpp"
#include "components/Pre4013.hpp"
#include "components/Pre4030.hpp"
#include "components/Pre4069.hpp"
#include "components/Pre4071.hpp"
#include "components/Pre4081.hpp"

#include "Factory.hpp"

void nts::ComponentFactory::addPrebuilts() {
    factory["4001"] = []() {return std::make_unique<Component4001>();};
    factory["4008"] = []() {return std::make_unique<Component4008>();};
    factory["4011"] = []() {return std::make_unique<Component4011>();};
    factory["4013"] = []() {return std::make_unique<Component4013>();};
    factory["4030"] = []() {return std::make_unique<Component4030>();};
    factory["4069"] = []() {return std::make_unique<Component4069>();};
    factory["4071"] = []() {return std::make_unique<Component4071>();};
    factory["4081"] = []() {return std::make_unique<Component4081>();};
}
