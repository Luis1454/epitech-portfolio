##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = palindrome

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra

CCFLAGSDEBUG = -g

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(CCFLAFSDEBUG)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all
