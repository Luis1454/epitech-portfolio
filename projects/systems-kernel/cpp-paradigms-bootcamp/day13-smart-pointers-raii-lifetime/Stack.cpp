/*
** EPITECH PROJECT, 2024
** Stack.cpp
** File description:
** Stack
*/

#include "Stack.hpp"

void Stack::push(double value) {
    stack.push(value);
}

double Stack::pop() {
    double value = 0;

    if (stack.empty())
        throw Error("Stack is empty");
    value = stack.top();
    stack.pop();
    return value;
}

double Stack::top() const {
    if (stack.empty())
        throw Error("Stack is empty");
    return stack.top();
}

void Stack::add() {
    if (stack.size() < 2)
        throw Error("Not enough operands");
    double a = pop();
    double b = pop();
    push(a + b);
}

void Stack::sub() {
    if (stack.size() < 2)
        throw Error("Not enough operands");
    double a = pop();
    double b = pop();
    push(a - b);
}

void Stack::mul() {
    if (stack.size() < 2)
        throw Error("Not enough operands");
    double a = pop();
    double b = pop();
    push(a * b);
}

void Stack::div() {
    if (stack.size() < 2)
        throw Error("Not enough operands");
    double a = pop();
    double b = pop();
    if (a == 0)
        throw Error("Division by zero");
    push(a / b);
}
