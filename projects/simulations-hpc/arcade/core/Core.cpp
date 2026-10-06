/*
** EPITECH PROJECT, 2024
** B-OOP-400-LIL-4-1-arcade-alexis.salaun
** File description:
** arcade
*/

#include "include/Core.hpp"
#include "include/Handling.hpp"
#include <functional>
#include "../graphicals/IDisplayModule.hpp"
#include "../games/IGame.hpp"

arc::ICore::ICore()
{
    key = 0;
}

arc::ICore::~ICore()
{
}

std::unique_ptr<IDisplayModule> arc::ICore::openGraphical(char *av, std::unique_ptr<IDisplayModule> displayModule)
{
    auto graphical = dl::my_dl_open(av);
    if (graphical == nullptr) {
        std::cerr << "Error: " << dl::my_dl_error() << std::endl;
        return nullptr;
    }
    auto entry_point = dl::my_dl_sym(graphical, "entryPoint");
    if (entry_point == nullptr) {
        std::cerr << "Error: " << dl::my_dl_error() << std::endl;
        return nullptr;
    }
    auto entry = reinterpret_cast<IDisplayModule* (*)()>(entry_point);
    displayModule = std::unique_ptr<IDisplayModule>(entry());
    displayModule->setWindow();
    return displayModule;
}

void arc::ICore::mainloop(std::unique_ptr<IDisplayModule> displayModule)
{
    Menu menu;
    menu.set_all("./lib");
    displayModule->loadFont("graphicals/fonts/arial.ttf");
    displayModule->clear();
    std::unique_ptr<IGame> gameModule = nullptr;
    std::string path = menu.get_games()[0];
    while (true) {
        if (displayModule->pollEvent() == 1)
            break;
        key = displayModule->getKeys();
        if (key == 36) {
            if (menu.get_game_is_loaded() == 0) {
                displayModule->clear();
                displayModule->closeWindow();
                break;
            }
            menu.set_game_is_loaded(NOT_LOADED);
            gameModule = nullptr;
        }
        if (menu.get_game_is_loaded() == NOT_LOADED) {
            displayModule->clear();
            displayModule = menu.display_menu(std::move(displayModule), key);
            displayModule->drawWindow();
        }
        if (menu.get_game_is_loaded() == LOADED) {
            auto game = dl::my_dl_open((std::string("./lib/") + menu.get_choice_games()).c_str());
            if (game == nullptr) {
                dl::my_dl_close(game);
            }
            auto entry_point = dl::my_dl_sym(game, "entryPoint");
            if (entry_point == nullptr) {
                dl::my_dl_close(game);
            }
            auto entry = reinterpret_cast<IGame* (*)()>(entry_point);
            gameModule = std::unique_ptr<IGame>(entry());
            menu.set_game_is_loaded(RUNNING);
        }
        if (gameModule != nullptr) {
            displayModule->clear();
            std::pair<int, int> dir = gameModule->getDir();

            if (!gameModule->getState() && !gameModule->isLost() && !gameModule->isWon()) {
                if (key != -1)
                    dir = std::make_pair(0, 0);
                dir = {
                    key == 71 ? -1 : key == 72 ? 1 : dir.first,
                    key == 73 ? -1 : key == 74 ? 1 : dir.second
                };
                gameModule->setDir(dir);
                gameModule->setState(gameModule->move());
            }
            gameModule->loop();
            for (auto shape : gameModule->getShapes()) {
                if (shape.type == SHAPE_RECT)
                    displayModule->drawRect(shape.x, shape.y, shape.width, shape.height, (Color)shape.color, shape.mode);
                if (shape.type == SHAPE_CIRCLE)
                    displayModule->drawCircle(shape.x, shape.y, shape.width, (Color)shape.color, shape.mode);
                if (shape.type == SHAPE_TEXT)
                    displayModule->drawText(shape.x, shape.y, shape.text, (Color)shape.color, shape.mode);
            }
            if (gameModule->getState() || gameModule->isLost() || gameModule->isWon()) {
                gameModule->clearShapes();
                displayModule->drawRect(0, 0, displayModule->getWidth(), displayModule->getHeight(), COLOR_AlphaBlack, TOP_LEFT_ALIGN);
                displayModule->drawText(-3, -1, gameModule->isWon() && !gameModule->isLost() ? "YOU WON !" : "GAME OVER", COLOR_White, CENTERED);
                displayModule->drawText(-8, 0, std::string("Your score: ") + std::to_string(gameModule->getScore()) + " points", COLOR_White, CENTERED);
                displayModule->drawText(-13, 2, "Press [ESC] to go back to menu", COLOR_White, CENTERED);
            }
            displayModule->drawWindow();
        }
    }
}
