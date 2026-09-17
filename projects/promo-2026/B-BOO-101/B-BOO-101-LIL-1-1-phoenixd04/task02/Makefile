##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## lib compiler
##

CC = gcc

SRC = $(wildcard *.c)

EXEC = concat_parameters.c

PATH = lib/phoenix

all:
	make -C $(PATH)
	gcc *.c -Iincludes -Llib/phoenix -lphoenix

clean:
	make clean -C $(PATH)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
