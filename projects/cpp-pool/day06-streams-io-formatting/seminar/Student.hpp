/*
** EPITECH PROJECT, 2024
** Student.hpp
** File description:
** Studient
*/

#include <iostream>
#include <iomanip>
#include <string>

#ifndef __STUDENT_HPP__
#define __STUDENT_HPP__

class Student {
    public:
        Student(std::string name) : name(name), energy(100)
        {std::cout << "Student " << name << ": I'm ready to learn C++." << std::endl;}

        bool learn(std::string text) {
            if (energy >= 42) {
                energy = energy - 42 > 0 ? energy - 42 : 0;
                std::cout << "Student " << name << ": " << text << std::endl;
                return true;
            } else {
                std::string::size_type pos = text.find("C++");
                while (pos != std::string::npos) {
                    text.replace(pos, 3, "shit");
                    pos = text.find("C++");
                }
                std::cout << "Student " << name << ": " << text << std::endl;
                return false;
            }
        }

        std::string getName(void)
        {
            return name;
        }

        int get_energy(void)
        {
            return energy;
        }

        void drink(std::string drink) {
            if (drink == "Red Bull") {
                energy = energy + 32 <= 100 ? energy + 32 : 100;
                std::cout << "Student " << name << ": Red Bull gives you wings!" << std::endl;
            } else if (drink == "Monster") {
                std::cout << "Student " << name << ": Unleash The Beast!" << std::endl;
                energy = energy + 64 <= 100 ? energy + 64 : 100;
            } else {
                std::cout << "Student " << name << ": ah, yes... enslaved moisture." << std::endl;
                energy = energy + 1 <= 100 ? energy + 1 : 100;
            }
        }

        ~Student()
        {std::cout << "Student " << name << ": Wow, much learning today, very smart, such C++." << std::endl;}

    private:
        std::string name;
        double energy;
};

#endif //__STUDENT_HPP__