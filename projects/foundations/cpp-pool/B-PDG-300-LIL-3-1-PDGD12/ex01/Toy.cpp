/*
** EPITECH PROJECT, 2024
** Toy.cpp
** File description:
** Toy
*/

#include "Toy.hpp"

Toy::Toy()
{
    type = BASIC_TOY;
    name = "toy";
    picture = Picture();
}

Toy::Toy(const ToyType &type, const std::string &name, const std::string &file)
{
    this->type = type;
    this->name = name;
    picture = Picture(file);
}

Toy::Toy(const Toy &toy)
{
    type = toy.type;
    name = toy.name;
    picture = toy.picture;
}

Toy &Toy::operator=(const Toy &toy)
{
    type = toy.type;
    name = toy.name;
    picture = toy.picture;
    return *this;
}

Toy::ToyType Toy::getType() const
{
    return type;
}

std::string Toy::getName() const
{
    return name;
}

std::string Toy::getAscii() const
{
    return picture.data;
}

void Toy::setName(const std::string &name)
{
    this->name = name;
}

bool Toy::setAscii(const std::string &file)
{
    return picture.getPictureFromFile(file);
}

std::ostream &operator<<(std::ostream &os, const Toy &toy)
{
    os << toy.getName() << std::endl << toy.getAscii() << std::endl;
    return os;
}