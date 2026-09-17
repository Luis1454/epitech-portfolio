/*
** EPITECH PROJECT, 2024
** Stack.hpp
** File description:
** Stack
*/

#ifndef STACK_HPP_
#define STACK_HPP_

#include <stack>
#include <stdexcept>

class Stack {
    public:
        class Error : public std::exception {
            private:
                std::string message;

            public:
                Error(const std::string& msg) : message(msg) {}

                const char* what() const noexcept override {
                    return message.c_str();
                }
        };

        void add();
        void sub();
        void mul();
        void div();
        void push(double value);

        double pop();
        double top() const;

    private:
        std::stack<double> stack;

};

#endif /* !STACK_HPP_ */
