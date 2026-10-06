##
## EPITECH PROJECT, 2022
## B-CPE-200-LIL-2-1-corewar-mathis.zucchero
## File description:
## Makefile
##

SRC =	src/args/display_usage/display_help.c 		\
		src/args/load_address_flag.c				\
		src/args/prog_number_flag.c					\
		src/args/nbr_cycle_dump_flag.c				\
		src/args/manage_arguments.c					\
		src/parsing/parsing_file.c					\
		src/parsing/parsing_buffer_corewar.c		\
		src/cycle_loop.c							\
		src/winner_loop.c							\
		src/main.c									\

NAME = corewar

TRYHARDER = -Werror
FLAGS = -Wall -Wextra
INCLUDE = -I include/
LIB = -L lib -lmy
DEBUG_FLAGS = -g

GCC = gcc -o $(NAME) $(SRC) $(FLAGS) $(INCLUDE) $(LIB)
GCC_DEBUG = gcc -o $(NAME) $(SRC) $(FLAGS) $(INCLUDE) $(LIB) $(DEBUG_FLAGS)

all: compile_lib $(NAME)

compile_lib:
	@ cd ./lib && make re

$(NAME):
	$(GCC)

clean:
	rm -f $(NAME)

fclean: clean
	@ cd ./lib && make fclean

re: fclean all

debug:
	$(GCC_DEBUG)
