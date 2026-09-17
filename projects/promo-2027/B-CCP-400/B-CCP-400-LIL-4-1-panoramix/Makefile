##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = panoramix

SRC = src/main.c \
	src/utils.c \
	src/druid.c \
	src/villager.c

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra -Werror -lpthread

LDFLAGS = -L.

CCFLAGSDEBUG = -g

IFLAGS = -I include/

all: $(EXEC)

$(EXEC): $(SRC)
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSDEBUG)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)

re: fclean all

check:
	coding-style . .
	cat coding-style-reports.log
	sudo rm coding-style-reports.log
