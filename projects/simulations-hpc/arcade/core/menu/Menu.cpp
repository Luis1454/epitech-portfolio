/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** menu
*/

#include "../include/Menu.hpp"
#include <dirent.h>
#include "../dlfonction/Dl.hpp"
#include "../../games/IGame.hpp"

Menu::Menu()
{
    nb_libs = 0;
    nb_games = 0;
    pos = 0;
    choice_libs = 0;
    choice_games = 0;
    game_is_loaded = 0;
    _space = 0;
}

Menu::~Menu()
{
}

std::unique_ptr<IDisplayModule> Menu::display_Libs(std::unique_ptr<IDisplayModule> displayModule, int size_for_pos)
{
    for (int i = 0; i < (int)_libs.size(); i++) {
        displayModule->drawText((displayModule->getWidth() / 2)- 6, size_for_pos + _space, _libs[i], COLOR_White, 2);
        _space++;
    }
    return displayModule;
}

std::unique_ptr<IDisplayModule> Menu::display_Games(std::unique_ptr<IDisplayModule> displayModule)
{
    for (int i = 0; i < (int)_games.size(); i++) {
        displayModule->drawText((displayModule->getWidth() / 2)- 6, _space, _games[i], COLOR_White, 2);
        _space++;
    }
    return displayModule;
}

std::unique_ptr<IDisplayModule> Menu::display_menu(std::unique_ptr<IDisplayModule> displayModule, int key)
{
    if (registerModule.name_of_player.size() <= 0)
        displayModule = registerModule.Register_part(std::move(displayModule), key);
    _space = 0;
    if (key == 74) {
        if (pos >= nb_libs - 1) {
            choice_libs = nb_libs - 1;
            if (pos <= nb_libs)
                pos += 2;
            if (pos >= nb_libs + nb_games + 1) {
                choice_games = nb_games - 1;
                pos = nb_libs + nb_games + 1;
            } else {
                if (pos != nb_libs + 1)
                    choice_games++;
                pos++;
            }
        } else {
            choice_libs++;
            pos++;
        }
    }
    if (key == 73) {
        if (choice_libs == 0) {
            choice_libs = 0;
            pos = 0;
        } else {
            if (pos >= nb_libs) {
                if (pos > nb_libs + nb_games)
                    choice_games--;
                else if (pos == nb_libs + 2)
                    pos -= 2;
                pos--;
            } else {
                choice_libs--;
                pos--;
            }
        }
    }
    if (key == 58) {
        if (pos >= nb_libs) {
            game_is_loaded = 1;
        } else {
            displayModule->closeWindow();
            std::string path = "./lib/" + _libs[choice_libs];
            displayModule = nullptr;
            auto graphical = dl::my_dl_open(path.c_str());
            if (graphical == nullptr) {
                dl::my_dl_close(graphical);
                return displayModule;
            }
            auto entry_point = dl::my_dl_sym(graphical, "entryPoint");
            if (entry_point == nullptr) {
                dl::my_dl_close(graphical);
                return displayModule;
            }
            auto entry = reinterpret_cast<IDisplayModule* (*)()>(entry_point);
            displayModule = std::unique_ptr<IDisplayModule>(entry());
            displayModule->loadFont("graphicals/fonts/arial.ttf");
            displayModule->setWindow();
            displayModule->clear();
        }
    }
    int size_for_pos = (displayModule->getHeight() / 2) - (nb_libs + nb_games);
    displayModule->drawRect((displayModule->getWidth() / 2) - 9, size_for_pos - 1, 15, nb_libs + nb_games + 8, COLOR_Grey, 2);
    displayModule->drawRect((displayModule->getWidth() / 2)- 7, pos + size_for_pos + 1, 10, 1, COLOR_Green, 2);
    displayModule->drawText((displayModule->getWidth() / 2)- 7, pos + size_for_pos + 1, ">", COLOR_White, 2);
    displayModule->drawText((displayModule->getWidth() / 2)- 6, size_for_pos, "libs:", COLOR_LightBlue, 2);
    displayModule = display_Libs(std::move(displayModule), size_for_pos + 1);
    displayModule->drawText((displayModule->getWidth() / 2)- 6, size_for_pos + _space + 2, "Game:", COLOR_Orange, 2);
    _space = size_for_pos + _space + 3;
    displayModule = display_Games(std::move(displayModule));
    displayModule->drawText((displayModule->getWidth() / 2)- 6, _space + 2, "User:", COLOR_Red, 2);
    displayModule->drawText((displayModule->getWidth() / 2), _space + 2, registerModule.name_of_player, COLOR_White, 2);
    return displayModule;
}

std::vector<std::string> Menu::get_files()
{
    return _files;
}

std::vector<std::string> Menu::get_games()
{
    return _games;
}

std::vector<std::string> Menu::get_Libs()
{
    return _libs;
}

void Menu::set_files(std::string files)
{
    DIR *dir;
    struct dirent *ent;
    if ((dir = opendir(files.c_str())) != NULL) {
        while ((ent = readdir(dir)) != NULL) {
            if (ent->d_name[0] != '.')
                _files.push_back(ent->d_name);
        }
        closedir(dir);
    } else {
        perror("");
    }
}

int Menu::get_game_is_loaded()
{
    return game_is_loaded;
}

void Menu::set_all(std::string path)
{
    set_files(path);
    set_games();
    set_libs();
    nb_libs = _libs.size();
    nb_games = _games.size();
}

std::string Menu::get_choice_games()
{
    return _games[choice_games];
}

int Menu::set_game_is_loaded(int value)
{
    game_is_loaded = value;
    return game_is_loaded;
}

void Menu::set_games()
{
    for (int i = 0; i < (int)_files.size(); i++) {
        std::string path = "./lib/" + _files[i];
        auto game = dl::my_dl_open(path.c_str());
        if (game == nullptr) {
            dl::my_dl_close(game);
            continue;
        }
        auto entry_point = dl::my_dl_sym(game, "entryPoint");
        if (entry_point == nullptr) {
            dl::my_dl_close(game);
            continue;
        }
        auto entry = reinterpret_cast<IGame* (*)()>(entry_point);
        IGame* gameModule = entry();
        if (gameModule->is_lib() == 0) {
            _games.push_back(_files[i]);
        }
        dl::my_dl_close(game);
    }
}

void Menu::set_libs()
{
    for (int i = 0; i < (int)_files.size(); i++) {
        std::string path = "./lib/" + _files[i];
        auto game = dl::my_dl_open(path.c_str());
        if (game == nullptr) {
            dl::my_dl_close(game);
            continue;
        }
        auto entry_point = dl::my_dl_sym(game, "entryPoint");
        if (entry_point == nullptr) {
            dl::my_dl_close(game);
            continue;
        }
        auto entry = reinterpret_cast<IDisplayModule* (*)()>(entry_point);
        std::unique_ptr<IDisplayModule> displayModulegame = std::unique_ptr<IDisplayModule>(entry());
        if (displayModulegame->is_lib() == 1) {
            _libs.push_back(_files[i]);
        }
        dl::my_dl_close(game);
    }
}
