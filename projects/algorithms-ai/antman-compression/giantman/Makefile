##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for the compression part
##

CC = gcc

EXEC = giantman

SRC = $(wildcard src/*.c)

CCFLAGS = -Wall -Wextra

LDFLAGS = -L ../lib/my/ -lmy

CCFLAGSDEBUG = -g

IFLAGS = -I ../include/

all: $(EXEC)

$(EXEC): $(SRC)
	$(MAKE) -C ../lib/my/ all
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSDEBUG)

fclean:
	rm -rf $(EXEC)

re: fclean all
