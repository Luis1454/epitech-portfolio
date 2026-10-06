##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = my_rpg

SRC = 	src/main.c 						\
		src/buttons.c 					\
		src/display/display_game.c 		\
		src/display/display_menu.c 		\
		src/init/init_menu.c			\
		src/load_map.c					\
		src/loader.c					\
		src/loop_window.c				\
		src/map.c						\
		src/menu.c						\
		src/my_str_to_array.c			\
		src/my_strdup.c					\
		src/player.c					\
		src/slider.c					\
		src/text.c						\
		src/init/init_game.c			\
		src/init/init_sounds.c			\
		src/move_player.c				\
		src/check_file_error_handling.c	\
		src/zoom_map.c					\
		src/inventory.c					\
		src/utils.c						\
		src/items.c						\
		src/check_hover.c				\
		src/init/init_all_items.c		\
		src/contain.c 					\
		src/open_map/open_map.c			\
		src/open_map/others.c			\
		src/open_map/node.c				\
		src/open_map/panel.c			\
		src/set_resolution_screen.c		\
		src/display/display_about_button.c			\
		src/display/display_settings.c	\
		src/ennemi.c	\
		src/open_map/assert_a.c

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra -lcsfml-graphics \
-lcsfml-system -lcsfml-window -lcsfml-audio

LDFLAGS = -L lib/my/ -lmy -lm -lc -lgcc

CCFLAGSDEBUG = -g

IFLAGS = -I include/

all: $(EXEC)

$(EXEC): $(SRC)
	make -sC lib/my/
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSDEBUG)

clean:
	rm -rf $(OBJ)
	rm -rf $(UNITEXEC)

fclean: clean
	rm -rf $(EXEC)
	make fclean -sC lib/my/

re: fclean all
