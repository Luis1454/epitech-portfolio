##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = rush3

SRC = $(wildcard *.c)

SRC_TEST = stumper.c

OBJ = $(SRC:.c=.o)

OBJ_TEST = $(SRC_TEST:.c=.o)

UNITEXEC = rush3_tests

CCFLAGS = -Wall -Wextra

LDFLAGS = -L lib/my/ -lmy

CCFLAGSDEBUG = -g

IFLAGS = -I include/

CCFLAGSTEST = -L tests/ -ltests --coverage -lcriterion

all: $(EXEC)

$(EXEC): $(SRC)
	$(MAKE) -C lib/my/ all
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSDEBUG)

tests_run: $(UNITEXEC)

$(UNITEXEC): $(OBJ_TEST)
	$(MAKE) -C lib/my/ all
	$(MAKE) -C tests/ all
	$(CC) -o $@ $(OBJ_TEST) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSTEST)

clean:
	rm -rf $(OBJ)
	rm -rf $(UNITEXEC)

fclean: clean
	rm -rf $(EXEC)
	rm -rf $(UNITEXEC)
	$(MAKE) -C lib/my/ fclean

re: fclean all

retest: fclean tests_run
