/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Stock.cpp
*/

#include "../../include/Kitchen/Stock.hpp"

Stock::Stock()
{
    _Dough = 5;
    _Tomato = 5;
    _Gruyere = 5;
    _Ham = 5;
    _Mushrooms = 5;
    _Steak = 5;
    _Eggplant = 5;
    _GoatCheese = 5;
    _ChiefLove   = 5;
}

Stock::~Stock()
{
}

void Stock::setDough(int Dough)
{
    _Dough = Dough;
}

void Stock::setTomato(int Tomato)
{
    _Tomato = Tomato;
}

void Stock::setGruyere(int Gruyere)
{
    _Gruyere = Gruyere;
}

void Stock::setHam(int Ham)
{
    _Ham = Ham;
}

void Stock::setMushrooms(int Mushrooms)
{
    _Mushrooms = Mushrooms;
}

void Stock::setSteak(int Steak)
{
    _Steak = Steak;
}

void Stock::setEggplant(int Eggplant)
{
    _Eggplant = Eggplant;
}

void Stock::setGoatCheese(int GoatCheese)
{
    _GoatCheese = GoatCheese;
}

void Stock::setChiefLove(int ChiefLove)
{
    _ChiefLove = ChiefLove;
}

int Stock::getDough()
{
    return _Dough;
}

int Stock::getTomato()
{
    return _Tomato;
}

int Stock::getGruyere()
{
    return _Gruyere;
}

int Stock::getHam()
{
    return _Ham;
}

int Stock::getMushrooms()
{
    return _Mushrooms;
}

int Stock::getSteak()
{
    return _Steak;
}

int Stock::getEggplant()
{
    return _Eggplant;
}

int Stock::getGoatCheese()
{
    return _GoatCheese;
}

int Stock::getChiefLove()
{
    return _ChiefLove;
}
