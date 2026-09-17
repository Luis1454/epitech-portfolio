/*
** EPITECH PROJECT, 2024
** Federation.hpp
** File description:
** day 07 AM
*/

#include <iostream>

#include "Destination.hpp"
#include "WarpSystem.hpp"
#include "Borg.hpp"

#ifndef FEDERATION_HPP_
#define FEDERATION_HPP_

namespace Federation {
    namespace Starfleet {
        class Captain {
            public:
                Captain(std::string name) {_name = name;}

                ~Captain(){}

                std::string getName(void) {return _name;}

                int getAge(void) {return _age;}

                void setAge(int age) {_age = age;}

            private:
                std::string _name;
                int _age;
        };

        class Ship {
            public:
                Ship(int length, int width, std::string name, short maxWarp, int torpedo = 0) {
                    _length = length;
                    _width = width;
                    _name = name;
                    _maxWarp = maxWarp;
                    _home = EARTH;
                    _location = _home;
                    _shield = 100;
                    _photonTorpedo = torpedo;
                    std::cout << "The ship USS " << _name << " has been finished." << std::endl;
                    std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
                    std::cout << "It can go to Warp " << _maxWarp << "!" << std::endl;
                    if (_photonTorpedo)
                        std::cout << "Weapons are set: " << _photonTorpedo << " torpedoes ready." << std::endl;
                }

                ~Ship(){}

                void setupCore(WarpSystem::Core *core) {
                    _core = core;
                    std::cout << "USS " << _name << ": The core is set." << std::endl;
                }

                void checkCore(void) {
                    std::cout << "USS " << _name << ": The core is " << (_core->checkReactor()->isStable() ? "" : "un") << "stable at the time." << std::endl;
                }

                void promote(Captain *captain) {
                    _captain = captain;
                    std::cout << _captain->getName() << ": I'm glad to be the captain of the USS " << _name << "." << std::endl;
                }

                bool move(int warp, Destination d) {
                    if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
                        _location = d;
                        return true;
                    }
                    return false;
                }

                bool move(int warp) {
                    if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
                        _location = _home;
                        return true;
                    }
                    return false;
                }

                bool move(Destination d) {
                    if (d != _location && _core->checkReactor()->isStable()) {
                        _location = d;
                        return true;
                    }
                    return false;
                }

                bool move(void) {
                    if (_core->checkReactor()->isStable()) {
                        _location = _home;
                        return true;
                    }
                    return false;
                }

                int getShield(void) {return _shield;}

                void setShield(int shield) {_shield = shield;}

                int getTorpedo(void) {return _photonTorpedo;}

                void setTorpedo(int torpedo) {_photonTorpedo = torpedo;}

                void fire(Borg::Ship *target) {
                    if (_photonTorpedo) {
                        _photonTorpedo--;
                        std::cout << _name << ": Firing on target. " << _photonTorpedo << " torpedoes remaining." << std::endl;
                        target->setShield(target->getShield() - 50);
                        if (target->getShield() <= 0)
                            std::cout << _name << ": No more torpedo to fire, " << _captain->getName() << "!" << std::endl;
                    } else
                        std::cout << _name << ": No enough torpedoes to fire, " << _captain->getName() << "!" << std::endl;
                }

            private:
                int _width;
                int _length;
                int _shield;
                short _maxWarp;
                int _photonTorpedo;
                std::string _name;
                Captain *_captain;
                Destination _home;
                Destination _location;
                WarpSystem::Core *_core;
        };

        class Ensign {
            public:
                Ensign(std::string name) {
                    _name = name;
                    std::cout << "Ensign " << _name << ", awaiting orders." << std::endl;
                }

                ~Ensign(){}

            private:
                std::string _name;
        };
    };
    class Ship {
        public:
            Ship(int length, int width, std::string name) : _length(length), _width(width), _name(name), _maxWarp(1) {
                _home = VULCAN;
                _location = _home;
                std::cout << "The independent ship " << _name << " just finished its construction." << std::endl;
                std::cout << "It is " << _length << " m in length and " << _width << " m in width." << std::endl;
            }

            ~Ship(){}

            void setupCore(WarpSystem::Core *core) {
                _core = core;
                std::cout << _name << ": The core is set." << std::endl;
            }

            void checkCore(void) {
                std::cout << _name << ": The core is " << (_core->checkReactor()->isStable() ? "" : "un") << "stable at the time." << std::endl;
            }

            bool move(int warp, Destination d) {
                if (warp <= _maxWarp && d != _location && _core->checkReactor()->isStable()) {
                    _location = d;
                    return true;
                }
                return false;
            }

            bool move(int warp) {
                if (warp <= _maxWarp && _core->checkReactor()->isStable()) {
                    _location = _home;
                    return true;
                }
                return false;
            }

            bool move(Destination d) {
                if (d != _location && _core->checkReactor()->isStable()) {
                    _location = d;
                    return true;
                }
                return false;
            }

            bool move(void) {
                if (_core->checkReactor()->isStable()) {
                    _location = _home;
                    return true;
                }
                return false;
            }

        private:
            int _width;
            int _length;
            short _maxWarp;
            std::string _name;
            Destination _home;
            Destination _location;
            WarpSystem::Core *_core;
    };
}

#endif /* !FEDERATION_HPP_ */
