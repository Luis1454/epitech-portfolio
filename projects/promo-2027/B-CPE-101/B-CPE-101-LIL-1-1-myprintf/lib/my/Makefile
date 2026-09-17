##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## lib compiler
##

CC = gcc
EXEC = libmy.a
SRC = $(wildcard *.c) \
../../sub_my_printf.c \
../../my_printf.c
OBJ = $(SRC:.c=.o)

all : $(EXEC)

$(EXEC) : $(OBJ)
	ar rc $(EXEC) $(OBJ)
	cp $(EXEC) ../..

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)
	rm -rf ../../$(EXEC)

re : fclean all
