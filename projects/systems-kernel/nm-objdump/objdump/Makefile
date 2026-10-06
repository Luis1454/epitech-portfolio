##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for objdump
##

CC = gcc

EXEC = my_objdump

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra

LDFLAGS = -ldl -lm

CCFLAGSDEBUG = -g

IFLAGS = -I include/

all: $(EXEC)
	mv $(EXEC) ../

$(EXEC): $(SRC)
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSDEBUG)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf ../$(EXEC)

re: fclean all
