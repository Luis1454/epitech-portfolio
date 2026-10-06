/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** menu
*/

#ifndef MENU_HPP_
    #define MENU_HPP_

#include <iostream>
#include <vector>
#include <string>
#include "../../graphicals/IDisplayModule.hpp"
#include "Register.hpp"
#include <memory>

enum State {
    NOT_LOADED,
    LOADED,
    RUNNING
};

class Menu {
    public:
        Menu();
        ~Menu();
        std::unique_ptr<IDisplayModule> display_Libs(std::unique_ptr<IDisplayModule> displayModule, int size_for_pos);
        std::unique_ptr<IDisplayModule> display_menu(std::unique_ptr<IDisplayModule> displayModule, int key);
        std::unique_ptr<IDisplayModule> display_Games(std::unique_ptr<IDisplayModule> displayModule);
        std::vector<std::string> get_files();
        std::vector<std::string> get_games();
        std::vector<std::string> get_Libs();
        void set_files(std::string files);
        int set_game_is_loaded(int value);
        void set_all(std::string path);
        std::string get_choice_games();
        int get_game_is_loaded();
        void set_games();
        void set_libs();
    private:
        std::vector<std::string> _files;
        std::vector<std::string> _games;
        std::vector<std::string> _libs;
        Register registerModule;
        int game_is_loaded;
        int choice_games;
        int choice_libs;
        int nb_games;
        int nb_libs;
        int _space;
        int pos;
};

#endif /* !MENU_HPP_ */
