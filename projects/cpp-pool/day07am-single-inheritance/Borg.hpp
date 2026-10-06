/*
** EPITECH PROJECT, 2024
** Borg.hpp
** File description:
** day 07 AM
*/

#include <iostream>
#include "WarpSystem.hpp"
#include "Destination.hpp"

#ifndef BORG_HPP
#define BORG_HPP

namespace Borg {
    class Ship {
        public:
            Ship(int weaponFrequency = 20, short repair = 3) : _weaponFrequency(weaponFrequency), repair(repair) {
                _core = nullptr;
                _maxWarp = 9;
                _side = 300;
                _shield = 100;
                _home = UNICOMPLEX;
                _location = _home;
                std::cout << "We are the Borgs. Lower your shields and surrender yourselves unconditionally." << std::endl;
                std::cout << "Your biological characteristics and technologies will be assimilated." << std::endl;
                std::cout << "Resistance is futile." << std::endl;
            }

            ~Ship(){}

            void setupCore(WarpSystem::Core *core) {_core = core;}

            void checkCore(void);

            bool move(int warp, Destination d);
            bool move(int warp);
            bool move(Destination d);
            bool move(void);

            int getShield(void);

            void setShield(int shield);

            int getWeaponFrequency(void);

            void setWeaponFrequency(int frequency);

            short getRepair(void);

            void setRepair(short repair);

        private:
            int _side;
            int _shield;
            int _weaponFrequency;
            short repair;
            short _maxWarp;
            Destination _home;
            Destination _location;
            WarpSystem::Core *_core;
    };
}

#endif /* !BORG_HPP */