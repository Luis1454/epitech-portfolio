/*
** EPITECH PROJECT, 2024
** Cmd.hpp
** File description:
** Cmd
*/

#ifndef CMD_HPP_
#define CMD_HPP_

#include "Parser.hpp"

namespace nts {
    class Cmd {
        public:
            Cmd(const std::string &file);
            ~Cmd();

            void parse(const std::string &file);
            void associate(const std::unique_ptr<nts::AComponent>
            &component, const std::vector<std::string> &link);
            void handler();
            void runSimulate();
            void simulate(std::unique_ptr<nts::AComponent> &component);
            void display();
            void start();
            void loop();
            void incTick();
            void setTick(std::size_t tick);
            void updateTmpPins();
            void initSpecials();

            bool assign();

            static void sigHandler(int sig);

            std::size_t getTick();
            std::unique_ptr<nts::AComponent> &getComponent(const std::string &name);

        private:
            std::size_t _tick = 0;
            Parser _parser;
            std::vector<std::unique_ptr<nts::AComponent>> _components;
            std::string _cmd;
            std::map<std::string, std::function<void()>> _cmdList = {
                {"display", [this]() {display();}},
                {"simulate", [this]() {runSimulate();}},
                {"loop", [this]() {loop();}},
                {"exit", []() {exit(0);}},
            };
    };
}

#endif /* !CMD_HPP_ */
