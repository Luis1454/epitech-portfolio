##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## Makefile at the root
##

CC = gcc

EXEC = 42sh

SRC =	src/main.c		\
		src/assert.c	\
		src/display.c	\
		src/env.c		\
		src/exec.c		\
		src/get.c		\
		src/handle.c	\
		src/my_cd.c		\
		src/node.c		\
		src/pipe.c		\
		src/redirect.c	\
		src/setenv.c	\
		src/fonc.c		\
		src/utils.c		\
		src/echo.c		\
		src/quotes.c	\
		src/catch_ctrl.c\
		src/multiple_pipe.c\
		src/split_str.c\
		src/andor.c\

TEST_SRC =	tests/test_my_printf.c			\
			tests/test_my_revstr.c			\
			tests/test_my_str_isalpha.c		\
			tests/test_my_str_islower.c		\
			tests/test_my_strcapitalize.c	\
			tests/test_my_strcat.c			\
			tests/test_my_strcmp.c			\
			tests/test_my_strncat.c			\
			tests/test_my_strncmp.c			\
			tests/test_my_strncpy.c			\
			tests/test_my_strstr.c			\

OBJ = $(SRC:.c=.o)

TEST_OBJ = $(TEST_SRC:.c=.o)

UNITEXEC = unit_tests

CCFLAGS = -Wall -Wextra

LDFLAGS = -L lib/my/ -lmy

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
	$(MAKE) fclean
