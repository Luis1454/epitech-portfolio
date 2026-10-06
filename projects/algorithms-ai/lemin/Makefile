##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Genreic Makefile
##

CC = gcc

EXEC = lem_in

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra

LDFLAGS = -L./lib/my -lmy

CCFLAGSDEBUG = -g

IFLAGS = -I ./include

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) -o $@ $(OBJ)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
