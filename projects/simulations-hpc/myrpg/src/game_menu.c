/*
** EPITECH PROJECT, 2022
** myrpg_final
** File description:
** game_menu.c
*/

#include "../include/my.h"
#include "../include/my_rpg.h"

// void display_game_menu(game_t *game)
// {
//     sfRectangleShape_setOutlineThickness(game->rect, 3);
//     sfRectangleShape_setOutlineColor(game->rect,
//    (sfColor){105, 78, 52, 255});
//     add_rect(game, (sfVector2f){game->size.x - 200, 0}, (sfVector2f){200,
//     game->size.y}, (sfColor){212, 193, 174, 255});
//     add_text(game, game->text, "Game Menu", (sfVector2f){game->size.x -
//     100, 50});
//     add_text(game, game->text, "Inventory", (sfVector2f){game->size.x -
//     100, 100});
//     button_handling(game, "lnventory", "lnventory");
//     add_text(game, game->text, "Stats", (sfVector2f){game->size.x - 100,
//     150});
//     button_handling(game, "Stats", "Stats");
//     add_text(game, game->text, "Quests", (sfVector2f){game->size.x - 100,
//     200});
//     button_handling(game, "Quests", "Quests");
//     add_text(game, game->text, "Settings", (sfVector2f){game->size.x -
//     100, 250});
//     button_handling(game, "Settings", "Settings");
//     add_text(game, game->text, "Quit", (sfVector2f){game->size.x - 100,
//     300});
//     button_handling(game, "Quit", "Quit");
//     add_text(game, game->text, "Save", (sfVector2f){game->size.x - 100,
//     350});
//     button_handling(game, "Save", "Save");
//     add_text(game, game->text, "Load", (sfVector2f){game->size.x - 100,
//     400});
//     button_handling(game, "Load", "Load");
//     add_text(game, game->text, "Return", (sfVector2f){game->size.x - 100,
//     450});
//     button_handling(game, "Return", "Return");
//     if (is_in_rect((sfIntRect){game->size.x - 200, 0, 200, game->size.y},
//     game->mouse_pos)) {
//         sfSound_play(game->sounds->click);
//         add_rect(game, (sfVector2f){game->size.x - 200, 0},(sfVector2f){200,
//         game->size.y}, sfTransparent);
//         if (game->event.type == sfEvtMouseButtonPressed) {
//             if (is_in_rect((sfIntRect){game->size.x - 200, 100, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 1;
//             if (is_in_rect((sfIntRect){game->size.x - 200, 150, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 2;
//             if (is_in_rect((sfIntRect){game->size.x - 200, 200, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 3;
//             if (is_in_rect((sfIntRect){game->size.x - 200, 250, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 4;
//             if (is_in_rect((sfIntRect){game->size.x - 200, 300, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 5;
//             if (is_in_rect((sfIntRect){game->size.x - 200, 350, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 6;
//             if (is_in_rect((sfIntRect){game->size.x - 200, 400, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 7;
//             if (is_in_rect((sfIntRect){game->size.x - 200, 450, 200, 50},
//             game->mouse_pos))
//                 game->menu_id = 0;
//         }
//     }
// }
