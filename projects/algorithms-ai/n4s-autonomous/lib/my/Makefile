##
## EPITECH PROJECT, 2022
## task 01
## File description:
## C pool day
##

SRC	=	my_compute_power_rec.c	\
		my_compute_square_root.c	\
		concat_params.c	\
		my_find_prime_sup.c	\
		my_getnbr.c	\
		my_isneg.c	\
		my_is_prime.c	\
		my_putchar.c	\
		my_put_nbr.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_show_word_array.c	\
		my_sort_int_array.c	\
		my_strcapitalize.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strcpy.c	\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c	\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c	\
		my_strlowcase.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strncpy.c	\
		my_strstr.c	\
		my_strupcase.c	\
		my_str_to_word_array.c	\
		concat_params.c	\
		my_tablen.c	\
		my_get_next_line.c	\
		my_strdup.c	\
		my_swap.c \
		my_ftoa.c

OBJ	=	 $(SRC:.c=.o)

CFLAGS = -g -Wall -Wextra

NAME	=	 libmy.a

HEADER	=	 my.h

WORKDIR	=	 ..

all:	 	$(NAME)

$(NAME):	$(OBJ)
		@ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
fclean:
		rm -f $(NAME)
		make clean

re:	fclean all
