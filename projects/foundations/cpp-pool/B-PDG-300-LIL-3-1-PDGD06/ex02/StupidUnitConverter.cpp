/*
** EPITECH PROJECT, 2024
** MyCat.cpp
** File description:
** day 06
*/

#include <iostream>
#include <iomanip>
#include <string>

double convert_unit(double value, std::string unit)
{
    return unit == "Celsius" ? (value * 9 / 5) + 32 : (value - 32) * 5 / 9;
}

bool check_format(std::string line, std::string sep)
{
    std::string::size_type pos = line.find(sep);
    std::string number = "";
    std::string unit = "";

    if (pos == std::string::npos)
        return false;
    number = line.substr(0, pos);
    unit = line.substr(pos + 1);
    return !(unit != "Fahrenheit" && unit != "Celsius");
}

int main(void)
{
    double celsius;

    std::string sep = " ";
    std::string line;
    std::string unit;
    double value;

    while (true) {
        std::getline(std::cin, line);
        if (std::cin.eof())
            break;
        if (check_format(line, sep)) {
            value = std::stod(line.substr(0, line.find(sep)));
            unit = line.substr(line.find(sep) + 1);
            std::cout << std::setw(16)
            << std::fixed << std::setprecision(3)
            << convert_unit(value, unit) << std::setw(16)
            << (unit == "Celsius" ? "Fahrenheit" : "Celsius") << std::endl;
        }
    }
    return 0;
}
