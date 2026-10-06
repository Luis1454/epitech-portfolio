##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## day 05
##

EXEC = libstring.a

SRC = init.c \
	delete.c \
	assign.c \
	append.c \
	at.c \
	clear.c \
	length.c \
	compare.c \
	copy.c \
	c_str.c \
	empty.c \
	find.c \
	insert.c \
	to_int.c \
	split.c \
	print.c

TESTS_SRC = $(wildcard tests/*.c)

OBJ = $(SRC:.c=.o)

all: $(EXEC)

$(EXEC): $(OBJ)
	ar rc $(EXEC) $(OBJ) $(CFLAGS)

tests: re
	gcc -o unit_tests $(TESTS_SRC) -L. -lstring -lcriterion --coverage
	./unit_tests
	rm -f *.gcno
	rm -f *.gcda
	rm -f $(OBJ)
	rm -f $(EXEC)
	rm -f unit_tests

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(EXEC)

re: fclean all
