/*
** EPITECH PROJECT, 2023
** B-YEP-400-LIL-4-1-zappy-alexis.salaun
** File description:
** Inventory.hpp
*/

#ifndef INVENTORY_HPP_
#define INVENTORY_HPP_

#include <iostream>
#include <map>
#include "Item.hpp"

class Inventory {
    public:
        Inventory();
        ~Inventory();

        void setItem(std::shared_ptr<Resource> resource, int qty);
        void dropItem(std::string item, int qty);
        void dropItem(std::string item);
        Item getItem(std::string item);

        void display(sf::RenderWindow &window, sf::Vector2f pos, sf::Font &font);

    private:
        std::map<std::string, Item> _items;
};

#endif /* !INVENTORY_HPP_ */
