##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = navy

SRC = $(wildcard src/*.c)

TEST_SRC = $(wildcard tests/*.c)

OBJ = $(SRC:.c=.o)

TEST_OBJ = $(TEST_SRC:.c=.o)

UNITEXEC = unit_tests

CCFLAGS = -Wall -Wextra

LDFLAGS = -L lib/my/ -lmy -lncurses

CCFLAGSDEBUG = -g

IFLAGS = -I include/

TESTFLAGS = -L tests/ -ltests --coverage -lcriterion

all: $(EXEC)

$(EXEC): $(SRC)
	$(MAKE) -C lib/my/ all
	$(CC) -o $@ $(SRC) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSDEBUG)

unit_tests: $(UNITEXEC)

$(UNITEXEC): $(TEST_OBJ)
	$(MAKE) -C lib/my/ all
	$(MAKE) -C tests/ all
	$(CC) -o $@ $(TEST_OBJ) $(TESTFLAGS) $(CCFLAGS) $(LDFLAGS) $(IFLAGS)

test_run:
	./$(UNITEXEC)

clean:
	rm -rf $(OBJ)
	rm -rf $(UNITEXEC)

fclean: clean
	rm -rf $(EXEC)
	rm -rf $(UNITEXEC)
	$(MAKE) -C tests/ fclean
	$(MAKE) -C lib/my/ fclean

re: fclean all

retest: fclean unit_tests
	./$(UNITEXEC)
	fclean
