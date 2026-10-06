##
## EPITECH PROJECT, 2022
## B-CPE-200-LIL-2-1-corewar-mathis.zucchero
## File description:
## Makefile
##

SRC =	my_strlen.c 		\
		my_putstr.c 		\
		my_putchar.c 		\
		my_put_nbr.c 		\
		my_printf.c 		\
		my_strcmp.c			\
		my_strncmp.c		\
		my_strdup.c			\
		my_str_isalpha.c	\
		my_strstr.c			\
		my_revstr.c			\
		my_getnbr.c			\
		my_strcat.c			\
		my_str_isnum.c		\


OBJ = $(SRC:.c=.o)

NAME = libmy.a

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
