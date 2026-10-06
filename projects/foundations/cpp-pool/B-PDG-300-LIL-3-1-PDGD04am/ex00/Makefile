##
## EPITECH PROJECT, 2024
## Makefike
## File description:
## day01
##

SRC = main.c

OBJ = $(SRC:.c=.o)

CC = gcc

NAME = z

CFLAGS = -W -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
