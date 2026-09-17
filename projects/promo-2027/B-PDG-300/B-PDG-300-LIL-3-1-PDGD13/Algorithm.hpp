/*
** EPITECH PROJECT, 2024
** Algorithm.hpp
** File description:
** Algorithm
*/

#ifndef ALGORITHM_HPP_
#define ALGORITHM_HPP_

template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template<typename T>
T min(T a, T b) {
    return (a < b ? a : b);
}

template<typename T>
T max(T a, T b) {
    return (a > b ? a : b);
}

template<typename T>
T abs(T a) {
    return (a < 0 ? -a : a);
}

template<typename T>
T clamp(T value, T min, T max) {
    return value < min ? min : value > max ? max : value;
}

#endif /* !ALGORITHM_HPP_ */