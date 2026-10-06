/*
** EPITECH PROJECT, 2024
** FruitBox.hpp
** File description:
** FruitBox
*/

#ifndef FRUITBOX_HPP_
#define FRUITBOX_HPP_

#include "IFruit.hpp"

typedef struct node_s {
    struct node_s *next;
    IFruit *data;
} node_t;

class FruitBox {
    public:
        FruitBox(int size);
        ~FruitBox();
        unsigned int getSize() const;
        unsigned int nbFruits() const;
        bool pushFruit(IFruit *fruit);
        IFruit *popFruit();
        node_t *head() const;

    protected:
        int _size;
        node_t *_head;
};

std::ostream &operator<<(std::ostream &os, const FruitBox &box);

#endif /* !FRUITBOX_HPP_ */
