##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Generic Makefile
##

CC = gcc

EXEC = my_ls

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra

LDFLAGS = -L./lib/my -lmy

CCFLAGSDEBUG = -g

IFLAGS = -I ./include

all: $(EXEC)

$(EXEC): $(OBJ)
	$(MAKE) -C lib/my/ all
	$(CC) -o $@ $(OBJ) $(CCFLAGS) $(LDFLAGS) $(IFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)
	$(MAKE) -C lib/my/ fclean

re: fclean all
