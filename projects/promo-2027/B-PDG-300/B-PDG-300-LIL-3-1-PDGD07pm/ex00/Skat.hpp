/*
** EPITECH PROJECT, 2024
** Skat.hpp
** File description:
** Skat
*/

#include <string>

#ifndef SKAT_HPP_
#define SKAT_HPP_

class Skat
{
    public :
        Skat(const std::string &name, int stimPaks);

        ~Skat();
        int &stimPaks();
        const std::string &name();
        void shareStimPaks(int number, int &stock);
        void addStimPaks(unsigned int number);
        void useStimPaks();
        void status();

    private:
        std::string _name;
        int _stimPaks;   
};

#endif //SKAT_HPP_
