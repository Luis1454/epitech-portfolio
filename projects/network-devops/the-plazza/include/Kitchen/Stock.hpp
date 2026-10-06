/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Stock.hpp
*/

#ifndef STOCK_HPP
    #define STOCK_HPP

    #include <map>
    #include <string>

class Stock {
    public:
        Stock();
        ~Stock();

        void setDough(int Dough);
        void setTomato(int Tomato);
        void setGruyere(int Gruyere);
        void setHam(int Ham);
        void setMushrooms(int Mushrooms);
        void setSteak(int Steak);
        void setEggplant(int Eggplant);
        void setGoatCheese(int GoatCheese);
        void setChiefLove(int ChiefLove);

        int getDough();
        int getTomato();
        int getGruyere();
        int getHam();
        int getMushrooms();
        int getSteak();
        int getEggplant();
        int getGoatCheese();
        int getChiefLove();

    private:
        int _Dough;
        int _Tomato;
        int _Gruyere;
        int _Ham;
        int _Mushrooms;
        int _Steak;
        int _Eggplant;
        int _GoatCheese;
        int _ChiefLove;
};

#endif /* !STOCK_HPP */