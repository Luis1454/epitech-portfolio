##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## unit tests compiler
##

CC = gcc
EXEC = libtests.a
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
