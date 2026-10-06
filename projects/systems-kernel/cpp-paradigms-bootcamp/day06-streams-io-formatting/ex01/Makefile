##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Makefile
##

CC = g++

NAME = MyCat

SRC = $(wildcard *.cpp)

OBJ = $(SRC:.cpp=.o)

CFLAGS = -std=c++20 -Wall -Wextra -Werror -I. -g

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(CFLAGS)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
