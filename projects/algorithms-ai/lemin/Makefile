##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## dsk
##

NAME = lem_in

SRC =  	src/main.c \
		src/file_error/error.c \
		src/file_error/file_error.c \
		src/file_error/simple_fonction.c \
		src/file_error/simple_verif.c \
		src/file_error/my_str_is_numb_modif.c \
		src/algo.c \
		src/assert.c \
		src/list.c \
		src/get_a.c \
		src/get_b.c \
		src/init.c

OBJ = $(SRC:.c=.o)

LIB = -L ./lib/my/ -lmy

CC = gcc

CFLAGS = -I./include/ -Wall -Wextra -g

all: $(NAME)

.SILENT: $(OBJ)

$(NAME): $(OBJ)
	@echo -e "\033[32;01m[--------make-------------]\033[;0m"
	@echo -e "gcc $(OBJ) -o $(NAME) $(LIB)"
	@make -C lib/my/ -s
	@gcc $(OBJ) -o $(NAME) $(LIB)

clean :
	@echo -e "\033[31;01m--------make clean-------------\033[;0m"
	rm -f $(OBJ)
	@make clean -C lib/my/ -s

fclean : clean
	@echo -e "\033[31;01m--------make fclean-------------\033[;0m"
	rm -f $(NAME)
	@make fclean -C lib/my/ -s

re : fclean all
