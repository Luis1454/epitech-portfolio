/*
** EPITECH PROJECT, 2024
** FruitUtils.hpp
** File description:
** FruitUtils
*/

#ifndef FRUITUTILS_HPP_
#define FRUITUTILS_HPP_

#include "FruitBox.hpp"
#include "IFruit.hpp"

class FruitUtils {
    public:
        FruitUtils(){}
        ~FruitUtils(){}

        void sort(FruitBox &unsorted, FruitBox &lemons,
        FruitBox &bananas, FruitBox &limes, FruitBox &raspberries);

    protected:
        bool _peeled = true;
};

#endif /* !FRUITUTILS_HPP_ */
