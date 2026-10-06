/*
** EPITECH PROJECT, 2024
** zappy
** File description:
** Item
*/

#include "../../include/Item.hpp"

Item::Item()
{
    _resource = nullptr;
    _quantity = 0;
}

Item::Item(std::shared_ptr<Resource> resource, int qty)
{
    _resource = resource;
    _quantity = qty;
}

Item::~Item()
{
}

int Item::getQuantity()
{
    return _quantity;
}

void Item::setQuantity(int qty)
{
    _quantity = qty;
}

void Item::addQuantity(int qty)
{
    _quantity += qty;
}

void Item::dropQuantity(int qty)
{
    _quantity -= qty;
}

std::shared_ptr<Resource> Item::getResource()
{
    return _resource;
}