/*
** EPITECH PROJECT, 2024
** BloodOrange.hpp
** File description:
** BloodOrange
*/

#ifndef BLOODORANGE_HPP_
#define BLOODORANGE_HPP_

// define it using the Orange class

#include "ACitrus.hpp"
#include "Orange.hpp"

class BloodOrange : public ACitrus, public Orange {
    public:
        BloodOrange(){}
        ~BloodOrange(){}

        std::string getName() const {return _name;}
        unsigned int getVitamins() const {return Orange::_peeled ? _vitamins : 0;}
        bool isPeeled() const {return Orange::_peeled;}
        void peel() {Orange::_peeled = true;}

    protected:
        std::string _name = "blood orange";
        unsigned int _vitamins = 6;

};

#endif /* !BLOODORANGE_HPP_ */
