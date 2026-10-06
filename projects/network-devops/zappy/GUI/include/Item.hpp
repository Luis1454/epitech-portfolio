/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Item
*/

#ifndef ITEM_HPP_
#define ITEM_HPP_

#include <memory>
#include "Resources/Resource.hpp"

class Item {
    public:
        Item();
        Item(std::shared_ptr<Resource> resource, int qty);
        ~Item();

        int getQuantity();
        void setQuantity(int qty);
        void addQuantity(int qty);
        void dropQuantity(int qty);

        std::shared_ptr<Resource> getResource();

    private:
        std::shared_ptr<Resource> _resource;
        int _quantity;
};

#endif /* !ITEM_HPP_ */
