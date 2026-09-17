##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## lib compiler
##

CC = gcc

SRC = $(wildcard *.c)

EXEC = show_params

all:
	make -C ../lib/phoenix
	$(CC) $(SRC) -o $(EXEC) -I../includes -L../lib/phoenix -lphoenix

clean:
	make clean -C ../lib/phoenix

fclean: clean
	rm -rf $(EXEC)

re: fclean all
