##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile at the root
##

CC = nasm
LD = ld

SRC =	src/strlen.asm \
		src/strchr.asm \
		src/strrchr.asm \
		src/memset.asm \
		src/memcpy.asm \
		src/strcmp.asm \
		src/memmove.asm \
		src/strncmp.asm \
		src/strcasecmp.asm \
		src/strstr.asm \
		src/strpbrk.asm \
		src/strcspn.asm \

OBJ = $(SRC:.asm=.o)

NAME = libasm.so

CFLAGS = -f elf64

LDFLAGS = -shared

all: $(NAME)

$(NAME): $(OBJ)
	$(LD) $(LDFLAGS) $(OBJ) -o $(NAME)

%.o: %.asm
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
