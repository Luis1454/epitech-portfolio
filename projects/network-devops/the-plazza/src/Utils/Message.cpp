/*
** EPITECH PROJECT, 2024
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Message
*/

#include "../../include/Utils/Message.hpp"

void Message::pack(int kitchen, int pizza, int size, int number)
{
    std::ostringstream oss;
    oss << kitchen << ";" << pizza << ";" << size << ";" << number;
    serialized_message = oss.str();
}

void Message::unpack(const std::string& serialized)
{
    std::istringstream iss(serialized);
    std::string kitchen_str, number_str, pizza_Id, size_Id;
    std::getline(iss, kitchen_str, ';');
    kitchen = std::stoi(kitchen_str);
    std::getline(iss, pizza_Id, ';');
    pizza = std::stoi(pizza_Id);
    std::getline(iss, size_Id, ';');
    size = std::stoi(size_Id);
    std::getline(iss, number_str, ';');
    number = std::stoi(number_str);
}

Message& Message::operator>(const std::tuple<int, int, int, int>& data)
{
    std::ostringstream oss;
    pack(std::get<0>(data), std::get<1>(data), std::get<2>(data), std::get<3>(data));
    return *this;
}

Message& Message::operator<(const std::string& serialized)
{
    unpack(serialized);
    return *this;
}

std::string Message::getSerializedMessage() const
{
    return serialized_message;
}

int Message::getKitchen() const
{
    return kitchen;
}

int Message::getPizza() const
{
    return pizza;
}

int Message::getSize() const
{
    return size;
}

int Message::getNumber() const
{
    return number;
}