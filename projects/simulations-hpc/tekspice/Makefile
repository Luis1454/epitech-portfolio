##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## day 05
##

NAME = nanotekspice

CC = g++

SRC = $(wildcard *.cpp) \
	$(wildcard components/*.cpp)

OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) -L.

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
