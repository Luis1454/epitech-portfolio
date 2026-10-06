/*
** EPITECH PROJECT, 2024
** KoalaBot.cpp
** File description:
** KoalaBot
*/

#include "KoalaBot.hpp"

KoalaBot::KoalaBot(){}

KoalaBot::~KoalaBot(){}

void KoalaBot::setParts(const Arms &arms)
{
    _arms = arms;
}

void KoalaBot::setParts(const Legs &legs)
{
    _legs = legs;
}

void KoalaBot::setParts(const Head &head)
{
    _head = head;
}

void KoalaBot::swapParts(Arms &arms)
{
    Arms tmp = arms;
    arms = _arms;
    _arms = tmp;
}

void KoalaBot::swapParts(Legs &legs)
{
    Legs tmp = legs;
    legs = _legs;
    _legs = tmp;
}

void KoalaBot::swapParts(Head &head)
{
    Head tmp = head;
    head = _head;
    _head = tmp;
}

void KoalaBot::informations() const
{
    std::cout << "[KoalaBot] " << _serial << std::endl;
    _arms.informations();
    _legs.informations();
    _head.informations();
}

bool KoalaBot::status() const
{
    if (_arms.isFunctional() && _legs.isFunctional() && _head.isFunctional())
        return true;
    return false;
}
