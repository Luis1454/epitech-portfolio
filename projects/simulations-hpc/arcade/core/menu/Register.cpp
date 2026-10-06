/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** Register
*/

#include "../include/Register.hpp"

Register::Register()
{
    name_of_player = "";
}

Register::~Register()
{
}

std::unique_ptr<IDisplayModule> Register::Register_part(std::unique_ptr<IDisplayModule> displayModule, int key)
{
    int turn = 0;
    displayModule->clear();
    while (true) {
        if (displayModule->pollEvent() == 1)
            exit(0);
        key = displayModule->getKeys();
        if (key == -1 && turn != 0)
            continue;
        turn = 1;
        if (key == 36) {
            displayModule->clear();
            displayModule->closeWindow();
            exit(0);
        }
        if (key == 58 && name_of_player.size() > 1)
            break;
        if (key == 59) {
            int length = name_of_player.length();
            if (length > 0)
                name_of_player = name_of_player.substr(0, length - 1);
        }
        else if (key >= 0 && key <= 25)
            name_of_player += min_to_maj(get_key_value(key));
        displayModule->clear();
        displayModule->drawRect((displayModule->getWidth() / 2) - 7, (displayModule->getHeight() / 2) - 1, 13, 4, COLOR_Grey, 2);
        displayModule->drawText((displayModule->getWidth() / 2) - 6,
        (displayModule->getHeight() / 2), "Enter name of player:", COLOR_White, 2);
        displayModule->drawText((displayModule->getWidth() / 2) - 6,
        (displayModule->getHeight() / 2) + 1, ">", COLOR_White, 2);
        if (name_of_player.size() >= 1)
            displayModule->drawText((displayModule->getWidth() / 2) - 5,
            (displayModule->getHeight() / 2) + 1, name_of_player, COLOR_White, 2);
        displayModule->drawWindow();
    }
    displayModule->clear();
    return displayModule;
}

void Register::set_name_of_player(std::string name)
{
    name_of_player = name;
}

std::string Register::get_name_of_player()
{
    return name_of_player;
}

char Register::get_key_value(int key)
{
    static const char keys[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h',
    'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u',
    'v', 'w', 'x', 'y', 'z'};
    if (key >= 0 || key <= 25)
        return keys[key];
    else
        return '\0';
}

char Register::min_to_maj(char c)
{
    if (c >= 'a' && c <= 'z')
        c = c - 32;
    return c;
}
