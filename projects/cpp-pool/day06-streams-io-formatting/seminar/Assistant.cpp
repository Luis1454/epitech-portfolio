/*
** EPITECH PROJECT, 2024
** Assistant.cpp
** File description:
** Assistant
*/

#include "Assistant.hpp"
#include "Student.hpp"
#include <fstream>

void Assistant::giveDrink(Student *student, std::string drink)
{
    std::cout << "Assistant " << id << ": drink this, " << student->getName() << " *sip coffee*" << std::endl;
    student->drink(drink);
}

std::string Assistant::readDrink(Student *student)
{
    std::ifstream file;
    std::string filename = student->getName() + ".drink";
    file.open(filename);
    if (!file.is_open())
        return "";
    std::string drink;
    std::getline(file, drink);
    file.close();
    std::cout << "Assistant " << id << ": " << student->getName() << " needs a " << drink << " *sip coffee*" << std::endl;
    return drink;
}

void Assistant::helpStudent(Student *student)
{
    std::string drink = readDrink(student);
    if (student->get_energy() >= 100) {
        std::cout << "Assistant " << id << ": " << student->getName() << " seems fine *sip coffee*" << std::endl;
        return;
    }
    if (drink != "")
        giveDrink(student, drink);
}

int main(void)
{
    Student *student = new Student("John");
    Assistant *assistant = new Assistant("Bob");
    student->learn("C++");
}