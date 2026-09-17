/*
** EPITECH PROJECT, 2024
** Droid.hpp
** File description:
** Droid
*/

#include <iostream>
#include "DroidMemory.hpp"

#ifndef DROID_HPP_
#define DROID_HPP_

class Droid {
    public:
        Droid(std::string serial);
        Droid(const Droid &droid);

        std::string getId() const;
        size_t getEnergy() const;
        size_t getAttack() const;
        size_t getToughness() const;
        std::string *getStatus() const;

        bool operator()(const std::string *task, size_t exp);

        void setId(std::string id);
        void setEnergy(size_t energy);
        void setStatus(std::string *status);

        Droid &operator=(const Droid &droid);
        bool operator==(const Droid &droid) const;
        bool operator!=(const Droid &droid) const;
        Droid &operator<<(size_t &energy);

        ~Droid();

    protected:
    private:
        std::string _id;
        size_t _energy;
        size_t _attack;
        size_t _toughness;
        std::string *_status;
        DroidMemory *_battleData;
};

#endif /* !DROID_HPP_ */
