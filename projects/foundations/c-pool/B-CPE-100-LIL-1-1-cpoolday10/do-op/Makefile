##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile for do-op
##

CC = gcc

EXEC = do-op

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

UNITEXEC = unit_tests

CCFLAGS = -Wall -Wextra

LDFLAGS = -L../lib/my/ -lmy

CCFLAGSDEBUG = -g

IFLAGS = -I../include/

TESTFLAGS = -L../tests/ -ltests --coverage -lcriterion

all: $(EXEC)

$(EXEC): $(OBJ)
	$(MAKE) -C ../lib/my/ all
	$(CC) -o $@ $(OBJ) $(CCFLAGS) $(LDFLAGS) $(IFLAGS)

mytest: $(UNITEXEC)

$(UNITEXEC): $(OBJ)
	$(MAKE) -C ../lib/my/ all
	$(MAKE) -C ../tests/ all
	$(CC) -o $@ $(OBJ) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(TESTFLAGS)

clean:
	rm -rf $(OBJ)
	rm -rf $(UNITEXEC)

fclean: clean
	rm -rf $(EXEC)
	rm -rf $(UNITEXEC)
	$(MAKE) -C ../tests/ fclean
	$(MAKE) -C ../lib/my/ fclean

re: fclean all

retest: fclean test
