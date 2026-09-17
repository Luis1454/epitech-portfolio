##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Generic Makefile
##

CC = gcc

EXEC = hidenp

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra

CCFLAGSDEBUG = -g

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) -o $@ $(OBJ) $(CCFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
