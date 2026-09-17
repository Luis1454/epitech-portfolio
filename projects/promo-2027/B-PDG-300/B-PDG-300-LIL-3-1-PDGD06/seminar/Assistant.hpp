/*
** EPITECH PROJECT, 2024
** Assistant.cpp
** File description:
** Assistant
*/

#ifndef __ASSISTANT_HPP__
#define __ASSISTANT_HPP__

#include <iostream>
#include "Student.hpp"

class Assistant {
    public:
        Assistant(std::string id) : id(id) {
            std::cout << "Assistant " << id << ": 'morning everyone *sip coffee*" << std::endl;
        }

        ~Assistant() {
            std::cout << "Assistant " << id << ": see you tomorrow at 9:00 *sip coffee*" << std::endl;
        }

        void giveDrink(Student *student, std::string drink);

        std::string readDrink(Student *student);

        void helpStudent(Student *student);

    private:
        std::string id;
};

#endif //__ASSISTANT_HPP__