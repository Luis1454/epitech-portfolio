##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Generic Makefile
##

CC = gcc

EXEC = my_world

SRC = src/brush.c \
	src/core.c \
	src/init.c \
	src/main.c \
	src/menu.c \
	src/sub.c \
	src/utils.c \
	src/view.c \
	src/axis.c \
	src/get_brush.c \
	src/get.c \
	src/sub_init.c \
	src/vertex.c \

OBJ = $(SRC:.c=.o)

CCFLAGS = -Wall -Wextra

LDFLAGS = -L./lib/my -lmy -lm -lc -lgcc

CSFMLFLAGS = -lcsfml-graphics -lcsfml-window -lcsfml-system

CCFLAGSDEBUG = -g

IFLAGS = -I ./includes/

all: $(EXEC)

$(EXEC): $(OBJ)
	$(MAKE) -C lib/my/ all
	$(CC) -o $(EXEC) $(SRC) $(LDFLAGS) $(CSFMLFLAGS)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(EXEC)
	$(MAKE) -C lib/my/ fclean

re: fclean all

valgrind:$(OBJ)
	$(MAKE) -C lib/my/ all
	$(CC) -o $(EXEC) -g $(OBJ) $(CCFLAGS) $(LDFLAGS) $(IFLAGS) $(CSFMLFLAGS)