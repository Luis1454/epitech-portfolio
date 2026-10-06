/*
** EPITECH PROJECT, 2024
** IFruit.hpp
** File description:
** IFruit
*/

#ifndef IFRUIT_HPP_
#define IFRUIT_HPP_

#include <iostream>

class IFruit {
    public:
        virtual ~IFruit(){}

        virtual std::string getName() const = 0;
        virtual unsigned int getVitamins() const = 0;
        virtual bool isPeeled() const = 0;
        virtual void peel() = 0;
};

std::ostream &operator<<(std::ostream &os, const IFruit &fruit);

#endif /* !IFRUIT_HPP_ */
