##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## lib compiler
##

CC = gcc

SRC = $(wildcard *.c)

EXEC = libphoenix.a

OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	ar rc $@ $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
