##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Genreic Makefile
##

CC = gcc

EXEC = calc

SRC = $(wildcard src/*.c)

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra

LDFLAGS = -L./lib/my -lmy

CCFLAGSDEBUG = -g

IFLAGS = -I ./include

all : $(EXEC)

$(EXEC) : $(OBJ)
	$(MAKE) -C lib/my/ all
	$(CC) -o $@ $(OBJ) $(CCFLAGS) $(LDFLAGS) $(IFLAGS)

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)
	$(MAKE) -C lib/my/ fclean

debug :
	$(CC) -o $(EXEC) $(SRC) $(CCFLAGSDEBUG) $(LDFLAGS) $(IFLAGS) $(CCFLAGS)

re : fclean all
