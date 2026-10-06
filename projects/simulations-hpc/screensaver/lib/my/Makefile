##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile for lib
##

CC = gcc
EXEC = libmy.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	ar rc $@ $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
