##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = cat

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)

UNITEXEC = cat

CCFLAGS = -Wall -Wextra

LDFLAGS = -L ../lib/my/ -lmy

CCFLAGSDEBUG = -g

IFLAGS = -I include/

CCFLAGSTEST = -L ../tests/ -ltests --coverage -lcriterion

all: $(EXEC)

$(EXEC): $(OBJ)
	$(MAKE) -C ../lib/my/ all
	$(CC) -o $@ $(OBJ) $(CCFLAGS) $(LDFLAGS) $(IFLAGS)

tests_run: $(UNITEXEC)

$(UNITEXEC): $(OBJ)
	$(MAKE) -C ../lib/my/ all
	$(MAKE) -C ../tests/ all
	$(CC) -o $@ $(OBJ) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CCFLAGSTEST)

clean:
	rm -rf $(OBJ)
	rm -rf $(UNITEXEC)

fclean: clean
	rm -rf $(EXEC)
	rm -rf $(UNITEXEC)
	$(MAKE) -C ../tests/ fclean
	$(MAKE) -C ../lib/my/ fclean

re: fclean all

retest: fclean tests_run
