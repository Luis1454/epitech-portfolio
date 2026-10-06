##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = strace

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

UNITEXEC = unit_tests

CCFLAGS = -Wall -Wextra -Werror -lelf

CCFLAGSDEBUG = -g

IFLAGS = -I include/

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(IFLAGS) $(CCFLAGSDEBUG)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
