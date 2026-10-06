/*
** EPITECH PROJECT, 2023
** B-CCP-400-LIL-4-1-theplazza-alexis.salaun
** File description:
** Parsing.cpp
*/

#include "../../include/Parsing/Parsing.hpp"
#include "../../include/Error/Error.hpp"
#include "../../include/Pizzas/Pizza.hpp"

Parsing::Parsing()
{
}

Parsing::~Parsing()
{
}

void Parsing::parseArguments(int ac, char **av)
{
    if (ac != 4)
        throw err::Error(err::List_error::NUMBER_ARG);
    try {
        _cookingTime = std::stof(av[1]);
        _numberOfCooks = std::stoi(av[2]);
        _restockTime = std::stof(av[3]);
    } catch (const std::invalid_argument& e) {
        throw err::Error(err::List_error::INVALID_ARG);
    } catch (const std::out_of_range& e) {
        throw err::Error(err::List_error::OUT_OF_RANGE);
    };
    if (_numberOfCooks <= 0)
        throw err::Error(err::List_error::INVALID_NUMBER_COOKS);
    if (_cookingTime <= 0)
        throw err::Error(err::List_error::COOKING_TIME);
    if (_restockTime <= 0)
        throw err::Error(err::List_error::RESTOCK_TIME);
}

Shell Parsing::parseCommand(std::string input)
{
    Shell shell;
    std::stringstream ss(input);
    ss >> shell.TYPE >> shell.SIZE >> shell.NUMBER;
    return shell;
}

bool Parsing::isValidType(const std::string& type)
{
    std::string lowerType = type;
    std::transform(lowerType.begin(), lowerType.end(), lowerType.begin(), ::tolower);
    lowerType[0] = std::toupper(lowerType[0]);
    for (const auto& i : pizza::pizzaTypeString)
        if (i.second == lowerType)
            return true;
    std::cout << err::error_messages[err::List_error::INVALID_TYPE].message << std::endl;
    return false;
}

bool Parsing::isValidSize(const std::string& size)
{
    for (const auto& i : pizza::pizzaSizeString)
        if (i.second == size)
            return true;
    std::cout << err::error_messages[err::List_error::VALID_SIZE].message << std::endl;
    return false;
}

bool Parsing::isValidNumber(const std::string& number)
{
    if (number.empty() || number[0] != 'x')
        return false;
    std::string digits = number.substr(1);
    if (digits.empty())
        return false;
    for (const auto& i : digits)
        if (!std::isdigit(i)) {
            std::cout << err::error_messages[err::List_error::VALID_NUMBER].message << std::endl;
            return false;
        }
    return true;
}

void Parsing::parseShell(std::string input)
{
    std::vector<std::string> input_split;
    std::string delimiter = ";";
    std::string token;
    size_t pos = 0;

    _shell.clear();
    while ((pos = input.find(delimiter)) != std::string::npos) {
        token = input.substr(0, pos);
        input_split.push_back(token);
        input.erase(0, pos + delimiter.length());
    }
    input_split.push_back(input);
    for (const auto& i : input_split) {
        Shell command = parseCommand(i);
        if (command.TYPE.empty() || command.SIZE.empty() || command.NUMBER.empty() ||
            !isValidType(command.TYPE) || !isValidSize(command.SIZE) || !isValidNumber(command.NUMBER)) {
            std::cout << "Please try again. See -h for help." << std::endl;
            _shell.clear();
            return;
        }
        _shell.push_back(command);
    }
}

float Parsing::getCoockingTime()
{
    return _cookingTime;
}

int Parsing::getNumberOfCooks()
{
    return _numberOfCooks;
}

float Parsing::getRestockTime()
{
    return _restockTime;
}

std::vector<Shell> Parsing::getShell()
{
    return _shell;
}

std::string Shell::lowerType() const
{
    std::string lowerType = TYPE;
    std::transform(lowerType.begin(), lowerType.end(), lowerType.begin(), ::tolower);
    return lowerType;
}
