/*
** EPITECH PROJECT, 2024
** Cmd.cpp
** File description:
** Cmd
*/

#include <iostream>
#include <csignal>
#include "Cmd.hpp"

nts::Cmd::Cmd(const std::string &filename)
{
    parse(filename);
    start();
}

nts::Cmd::~Cmd() {}

void nts::Cmd::setTick(std::size_t tick) {
    _tick = tick;
}

void nts::Cmd::incTick() {
    _tick++;
}

std::size_t nts::Cmd::getTick() {
    return _tick;
}

bool nts::Cmd::assign() {
    if (_cmd.find('=') != std::string::npos) {
        std::string left = _cmd.substr(0, _cmd.find('='));
        std::string right = _cmd.substr(_cmd.find('=') + 1, _cmd.size());

        for (const auto &component : _components)
            if (component->getName() == left
            && (component->getCategory() == "input" || component->getCategory() == "clock")
            && (right == "0" || right == "1" || right == "U")) {
                component->setPinState(right);
                return true;
            }
    }
    return false;
}

void nts::Cmd::handler() {
    if (assign())
        return;
    if (_cmdList.find(_cmd) != _cmdList.end())
        _cmdList[_cmd]();
    else
        std::cerr << "Invalid command" << std::endl;
}

void nts::Cmd::display() {
    std::cout << "tick: " << _tick << std::endl;

    std::cout << "input(s):" << std::endl;
    for (const auto &component : _components)
        if (component->getCategory() == "input" || component->getCategory() == "clock")
            std::cout << "  " << component->getName() << ": " << component->getPinState() << std::endl;

    std::cout << "output(s):" << std::endl;
    for (const auto &component : _components)
        if (component->getCategory() == "output")
            std::cout << "  " << component->getName() << ": " << component->getPinState() << std::endl;
}

void nts::Cmd::sigHandler(int sig) {
    if (sig == SIGINT)
        exit(0);
}

void nts::Cmd::loop() {
    std::signal(SIGINT, sigHandler);

    while (True) {
        runSimulate();
        display();
    }
}

void nts::Cmd::start() {
    initSpecials();
    updateTmpPins();

    while (true) {
        _cmd.clear();
        std::cout << "> ";
        std::cin >> _cmd;
        if (std::cin.eof())
            exit(0);
        handler();
    }
}

void nts::Cmd::associate(const std::unique_ptr<nts::AComponent>
&component, const std::vector<std::string> &link) {
    for (const auto &other : _components)
        if (component->getName() == link[0] && other->getName() == link[2]) {
            component->setPin(std::stoi(link[1]), nts::Tristate::Undefined);
            component->setLink(std::stoi(link[1]), other, std::stoi(link[3]));
            other->setChild(std::stoi(link[3]), component, std::stoi(link[1]));
        }
}

void nts::Cmd::parse(const std::string &filename) {
    std::size_t id = 0;
    _parser = nts::Parser(filename);
    nts::ComponentFactory factory;

    for (const auto &prebuilt : _parser.getChipsetsPrebuilt()) {
        auto component = factory.createComponent(prebuilt);
        if (component) {
            component->setName(_parser.getChipsets()[id++]);
            component->setCategory(prebuilt);
            _components.push_back(std::move(component));
        }
    }

    for (const auto &component : _components)
        for (const auto &link : _parser.getLinks())
            associate(component, link);
}

std::unique_ptr<nts::AComponent> &nts::Cmd::getComponent(const std::string &name) {
    for (auto &component : _components)
        if (component->getName() == name)
            return component;
    throw std::runtime_error("Component not found");
}

void nts::Cmd::simulate(std::unique_ptr<nts::AComponent> &component) {
    nts::Tristate state = component->compute(getTick());
    for (const auto &link : component->getLinks()) {
        getComponent(link.second.first)->setPin(link.second.second, state);
        simulate(getComponent(link.second.first));
    }
}

void nts::Cmd::initSpecials() {
    for (auto &component : _components) {
        if (component->getCategory() == "true")
            component->setPin(1, nts::Tristate::True);
        if (component->getCategory() == "false")
            component->setPin(1, nts::Tristate::False);
    }
}

void nts::Cmd::updateTmpPins() {
    for (auto &component : _components)
        for (auto &pin : component->getPins())
            component->setOldPin(pin.first, pin.second);
}

void nts::Cmd::runSimulate() {
    for (auto &component : _components)
        if (component->getCategory() == "input"
        || component->getCategory() == "clock"
        || component->getCategory() == "true"
        || component->getCategory() == "false")
            simulate(component);

    for (auto &component : _components)
        if (component->getCategory() == "output")
            for (const auto &link : component->getLinks())
                component->setPin(link.first,
                getComponent(link.second.first)->getPin(link.second.second));

    updateTmpPins();
    incTick();
}
