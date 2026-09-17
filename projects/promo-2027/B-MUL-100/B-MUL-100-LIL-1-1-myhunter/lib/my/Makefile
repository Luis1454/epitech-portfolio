##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lib compiler
##

CC = gcc
EXEC = libmy.a
SRC = $(wildcard *.c)
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	ar rc $(EXEC) $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
